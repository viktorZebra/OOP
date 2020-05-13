#include "MyVector.h"

#include <corecrt_math_defines.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

template<typename Type>
MyVector<Type>::~MyVector<Type>()
{
    if (data)
        data.reset();
}

template<typename Type>
MyVector<Type>::MyVector()
{
    countElem = 0;
    allocMemory(countElem);
}

template<typename Type>
MyVector<Type>::MyVector(int countElements)
{
    if (countElements < 0)
        throw EmptyError("Error: ");

    countElem = countElements;
    allocMemory(countElem);

    if (!data)
        throw MemError("Error: ");

    MyIterator<Type> iter(*this);
    for (; iter; iter++)
        *iter = 0;
}

template<typename Type>
MyVector<Type>::MyVector(int countElements, Type value, ...)
{
    if (countElements < 1)
        throw EmptyError("Error: ");

    countElem = countElements;
    allocMemory(countElem);

    if (!data)
        throw MemError("Error: ");

    MyIterator<Type> iter(*this);
    va_list valuePtr;
    va_start(valuePtr, value);
    for (; iter; iter++)
    {
        *iter = value;
        value = va_arg(valuePtr, Type);
    }
    va_end(valuePtr);
}

template<typename Type>
MyVector<Type>::MyVector(int countElements, Type* valueArr)
{
    if (countElements <= 0)
        throw EmptyError("Error: ");

    countElem = countElements;
    allocMemory(countElem);

    MyIterator<Type> iter(*this);
    for (int i = 0; iter; i++, iter++)
        *iter = valueArr[i];
}

template<typename Type>
MyVector<Type>::MyVector(std::initializer_list<Type> args)
{
    if (args.size() == 0)
        MyVector();

    countElem = int(args.size());
    allocMemory(countElem);

    MyIterator<Type> iter(*this);
    for (auto& element : args)
    {
        *iter = element;
        iter++;
    }
}

template<typename Type>
MyVector<Type>::MyVector(MyVector<Type>&& vec)
{
    countElem = vec.countElem;
    allocMemory(countElem);

    data = vec.data;
    vec.data.reset();
}

template<typename Type>
Type& MyVector<Type>::getElemMyVector(int index)
{
    if (index < 0 || index >= countElem)
        throw IndexError("Error: ", index);

    MyIterator<Type> iter(*this);
    for (int i = 0; i < index; i++, iter++);

    return *iter;
}

template<typename Type>
const Type& MyVector<Type>::getElemMyVector(int index) const
{
    if (index < 0 || index >= countElem)
        throw IndexError("Error: ", index);

    MyIterator<Type> iter(*this);
    for (int i = 0; i <= index; i++, iter++);

    return *iter;
}

template <typename Type>
bool MyVector<Type>::operator ==(const MyVector<Type>& vec) const
{
    bool equal = true;

    if (countElem != vec.countElem)
        return false;
    else
    {
        MyIterator<Type> iter1(*this);
        MyIterator<Type> iter2(vec);

        for (; iter1 && equal; iter1++, iter2++)
            if (fabs(*iter1 - *iter2) > EPS)
                equal = false;
    }
    return equal;
}

template <typename Type>
bool MyVector<Type>::operator !=(const MyVector<Type>& vec) const
{
    if (*this == vec)
        return false;
    else
        return true;
}

template<typename Type>
Type MyVector<Type>::len(void) const
{
    if (countElem < 0)
        throw EmptyError("Error: ");

    MyIterator<Type> iter(*this);
    double sum = 0;
    for (; iter; iter++)
        sum += *iter * *iter;

    return sqrt(sum);
}

template <typename Type>
Type MyVector<Type>::operator *(const MyVector<Type>& vec) const
{
    if (countElem < 0 || vec.countElem < 0)
        throw EmptyError("Error: ");

    int max_len = max(countElem, vec.countElem);
    MyVector<Type> new_MyVector(max_len);
    multMyVectors(new_MyVector, *this, vec);

    return new_MyVector.sumAllElem();
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator +(const MyVector<Type>& vec) const
{
    if (countElem < 0 || vec.countElem < 0)
        throw EmptyError("Error");

    int max_len = max(countElem, vec.countElem);
    MyVector<Type> new_MyVector(max_len);
    sumMyVectors(new_MyVector, *this, vec);

    return new_MyVector;
}

template <typename Type>
MyVector<Type>& MyVector<Type>::operator +=(const MyVector<Type>& vec)
{
    if (countElem < 0 || vec.countElem < 0)
        throw EmptyError("Error");

    sumMyVectors(*this, *this, vec);

    return *this;
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator -(const MyVector<Type>& vec) const
{
    if (countElem < 0 || vec.countElem < 0)
        throw EmptyError("Error");

    int max_len = max(countElem, vec.countElem);
    MyVector<Type> new_MyVector(max_len);
    differenceMyVectors(new_MyVector, *this, vec);

    return new_MyVector;
}

template <typename Type>
MyVector<Type>& MyVector<Type>::operator -=(const MyVector<Type>& vec)
{
    if (countElem < 0 || vec.countElem < 0)
        throw EmptyError("Error");

    differenceMyVectors(*this, *this, vec);

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator *=(const Type& mult)
{
    if (countElem < 0)
        throw EmptyError("Error");

    MyIterator<Type> iter(*this);
    for (; iter; iter++)
        *iter *= mult;

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator /=(const Type& div)
{
    if (!div)
        throw ZeroDivError("Error: ");

    Type div_new = 1 / div;
    *this *= div_new;

    return *this;
}

template<typename Type>
Type MyVector<Type>::sumAllElem()
{
    if (countElem < 0)
        throw EmptyError("Error");

    MyIterator<Type> iter(*this);
    Type sum = 0;
    for (; iter; iter++)
        sum += *iter;

    return sum;
}

template<typename Type>
double MyVector<Type>::angleBetweenMyVectors(const MyVector<Type>& vec) const
{
    if (!this->len() || !vec.len())
        throw ZeroDivError("Error: ");

    double angle = (*this * vec) / (this->len() * vec.len());
    return acos(angle) * 180 / M_PI;
}

template<typename Type>
bool MyVector<Type>::isSingle() const
{
    if (abs(this->len() - 1) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
bool MyVector<Type>::isZero() const
{
    if (this->len() == 0)
        return true;
    else
        return false;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator &=(const MyVector<Type>& vec)
{
    if (countElem != 3)
        return *(new MyVector<Type>);

    double x = data.get()[1] * vec.data.get()[2] - data.get()[2] * vec.data.get()[1];
    double y = data.get()[2] * vec.data.get()[0] - data.get()[0] * vec.data.get()[2];
    double z = data.get()[0] * vec.data.get()[1] - data.get()[1] * vec.data.get()[0];

    *this = MyVector<Type>(3, x, y, z);
    return *this;
}

template<typename Type>
MyVector<Type> MyVector<Type>::operator &(const MyVector<Type>& vec) const
{
    if (countElem != 3)
        return MyVector<Type>();

    double x = data.get()[1] * vec.data.get()[2] - data.get()[2] * vec.data.get()[1];
    double y = data.get()[2] * vec.data.get()[0] - data.get()[0] * vec.data.get()[2];
    double z = data.get()[0] * vec.data.get()[1] - data.get()[1] * vec.data.get()[0];

    MyVector<Type> new_MyVector(3, x, y, z);
    return new_MyVector;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator =(const MyVector<Type>& vec)
{
    countElem = vec.countElem;
    allocMemory(countElem);

    MyIterator<Type> iterNew(*this);
    MyIterator<Type> iter(vec);
    for (; iterNew; iterNew++, iter++)
        *iterNew = *iter;

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator =(std::initializer_list<Type> args)
{
    countElem = int(args.size());
    allocMemory(countElem);

    MyIterator<Type> iter(*this);
    for (auto& element : args)
    {
        *iter = element;
        iter++;
    }

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator =(MyVector<Type>&& vec)
{
    countElem = vec.countElem;
    allocMemory(countElem);
    data = vec.data;
    vec.data.reset();

    return *this;
}

template<typename Type>
MyVector<Type>::MyVector(const MyVector<Type>& vec)
{
    countElem = vec.countElem;
    allocMemory(countElem);

    MyIterator<Type> iterNew(*this);
    MyIterator<Type> iter(vec);
    for (; iterNew; iter++, iterNew++)
        *iterNew = *iter;
}

template<typename Type>
Type& MyVector<Type>::operator [](int index)
{
    return getElemMyVector(index);
}

template<typename Type>
const Type& MyVector<Type>::operator [](int index) const
{
    return getElemMyVector(index);
}

template<typename Type>
bool MyVector<Type>::setElemMyVector(int index, const Type& num)
{
    if (index < 0 || index >= countElem)
        return false;

    *(data.get() + index) = num;
    return true;
}

template<typename Type>
MyVector<Type> MyVector<Type>::getSingleMyVector() const
{
    MyVector<Type> new_MyVector(*this);
    Type len = this->len();

    MyIterator<Type> iter(new_MyVector);
    for (; iter; iter++)
        *iter /= len;

    return new_MyVector;
}

template<typename Type>
int MyVector<Type>::size() const
{
    return countElem;
}

template<typename Type>
bool MyVector<Type>::isCollinearity(const MyVector<Type>& vec) const
{
    if (this->angleBetweenMyVectors(vec) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
bool MyVector<Type>::isOrthogonality(const MyVector<Type>& vec) const
{
    if (abs(this->angleBetweenMyVectors(vec) - 90) < EPS)
        return true;
    else
        return false;
}

template <typename Type>
void MyVector<Type>::sumMyVectors(MyVector<Type>& result, const MyVector<Type>& vec1, const MyVector<Type>& vec2) const
{
    MyIterator<Type> iter_result(result);
    MyIterator<Type> iter_vec1(vec1);
    MyIterator<Type> iter_vec2(vec2);

    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.countElem)
            *iter_result = *iter_vec2;
        else if (i >= vec2.countElem)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 + *iter_vec2;
    }
}

template <typename Type>
void MyVector<Type>::differenceMyVectors(MyVector<Type>& result, const MyVector<Type>& vec1, const MyVector<Type>& vec2) const
{
    MyIterator<Type> iter_result(result);
    MyIterator<Type> iter_vec1(vec1);
    MyIterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.countElem)
            *iter_result = -*iter_vec2;
        else if (i >= vec2.countElem)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 - *iter_vec2;
    }
}

template <typename Type>
void MyVector<Type>::multMyVectors(MyVector<Type>& result, const MyVector<Type>& vec1, const MyVector<Type>& vec2) const
{
    MyIterator<Type> iter_result(result);
    MyIterator<Type> iter_vec1(vec1);
    MyIterator<Type> iter_vec2(vec2);
    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= vec1.countElem || i >= vec2.countElem)
            *iter_result = 0;
        else
            *iter_result = *iter_vec1 * *iter_vec2;
    }
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator -()
{
    MyVector<Type> new_MyVector(*this);
    MyIterator<Type> iter(new_MyVector);
    for (; iter; iter++)
        *iter = -*iter;

    return new_MyVector;
}

template <typename Type>
void MyVector<Type>::allocMemory(int countElem)
{
    data.reset();
    shared_ptr<Type> sp_temp(new Type[countElem], default_delete<Type[]>());
    data = sp_temp;
}
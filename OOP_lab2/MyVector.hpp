#include "MyVector.h"

#include <corecrt_math_defines.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

template<typename Type>
ostream& operator <<(ostream& os, const MyVector<Type>& vec)
{
    MyIterator<Type> iter(vec);

    if (!iter)
    {
        os << "MyVector is empty.";
        return os;
    }

    os << '(' << *iter;
    for (iter++; iter; iter++)
        os << ", " << *iter;
    os << ')';

    return os;
}

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
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    countElem = countElements;
    allocMemory(countElem);

    if (!data)
    {
        time_t t_time = time(NULL);
        throw MemError(__FILE__, __LINE__, ctime(&t_time));
    }

    MyIterator<Type> iter(*this);
    for (; iter; iter++)
        *iter = 0;
}

template<typename Type>
MyVector<Type>::MyVector(int countElements, Type value, ...)
{
    if (countElements < 1)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    countElem = countElements;
    allocMemory(countElem);

    if (!data)
    {
        time_t t_time = time(NULL);
        throw MemError(__FILE__, __LINE__, ctime(&t_time));
    }

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
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

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
    {
        time_t t_time = time(NULL);
        throw IndexError(__FILE__, __LINE__, ctime(&t_time));
    }

    MyIterator<Type> iter(*this);
    for (int i = 0; i < index; i++, iter++);

    return *iter;
}

template<typename Type>
const Type& MyVector<Type>::getElemMyVector(int index) const
{
    if (index < 0 || index >= countElem)
    {
        time_t t_time = time(NULL);
        throw IndexError(__FILE__, __LINE__, ctime(&t_time));
    }

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
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

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
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    int max_len = max(countElem, vec.countElem);
    MyVector<Type> result(this->multMyVectors(vec));

    return result.sumAllElem();
}

template <typename Type>
Type MyVector<Type>::operator *=(const MyVector<Type>& vec) const
{
    if (countElem < 0 || vec.countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    int max_len = max(countElem, vec.countElem);
    MyVector<Type> result(max_len);

    result = this->multMyVectors(vec);

    return result.sumAllElem();
}

template <typename Type>
MyVector<Type>& MyVector<Type>::multiplyScalToVector(const MyVector<Type>& vec)
{
    if (countElem < 0 || vec.countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    int max_len = max(countElem, vec.countElem);
    MyVector<Type> result(max_len);

    result = this->multMyVectors(vec);

    return result.sumAllElem();
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator +(const MyVector<Type>& vec) const
{
    if (countElem < 0 || vec.countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    return this->sumMyVectors(vec);
}

template <typename Type>
MyVector<Type>& MyVector<Type>::operator +=(const MyVector<Type>& vec)
{
    if (countElem < 0 || vec.countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    return this->sumMyVectors(vec);
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator -(const MyVector<Type>& vec) const
{
    if (countElem < 0 || vec.countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    return this->differenceMyVectors(vec);
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator -=(const MyVector<Type>& vec)
{
    if (countElem < 0 || vec.countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }


    return this->differenceMyVectors(vec);
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator *(const Type& mult)
{
    if (countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    MyIterator<Type> iter(*this);
    for (; iter; iter++)
        *iter *= mult;

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator *=(const Type& mult)
{
    if (countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    MyIterator<Type> iter(*this);
    for (; iter; iter++)
        *iter *= mult;

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator /=(const Type& div)
{
    if (!div)
    {
        time_t t_time = time(NULL);
        throw ZeroDivError(__FILE__, __LINE__, ctime(&t_time));
    }

    Type div_new = 1 / div;
    *this *= div_new;

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::operator /(const Type& div)
{
    if (!div)
    {
        time_t t_time = time(NULL);
        throw ZeroDivError(__FILE__, __LINE__, ctime(&t_time));
    }

    Type div_new = 1 / div;
    *this *= div_new;

    return *this;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::divToNumber(const Type& div)
{
    if (!div)
    {
        time_t t_time = time(NULL);
        throw ZeroDivError(__FILE__, __LINE__, ctime(&t_time));
    }

    Type div_new = 1 / div;
    *this *= div_new;

    return *this;
}



template<typename Type>
Type MyVector<Type>::sumAllElem()
{
    if (countElem < 0)
    {
        time_t t_time = time(NULL);
        throw EmptyError(__FILE__, __LINE__, ctime(&t_time));
    }

    MyIterator<Type> iter(*this);
    Type sum = 0;
    for (; iter; iter++)
        sum += *iter;

    return sum;
}

template<typename Type>
Type MyVector<Type>::angleBetweenMyVectors(const MyVector<Type>& vec) const
{
    if (!this->len() || !vec.len())
    {
        time_t t_time = time(NULL);
        throw ZeroDivError(__FILE__, __LINE__, ctime(&t_time));
    }

    Type angle = (*this * vec) / (this->len() * vec.len());
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

    double x = data[1] * vec.data[2] - data[2] * vec.data[1];
    double y = data[2] * vec.data[0] - data[0] * vec.data[2];
    double z = data[0] * vec.data[1] - data[1] * vec.data[0];

    *this = MyVector<Type>(3, x, y, z);
    return *this;
}

template<typename Type>
MyVector<Type> MyVector<Type>::operator &(const MyVector<Type>& vec) const
{
    if (countElem != 3)
        return MyVector<Type>();

    double x = data[1] * vec.data[2] - data[2] * vec.data[1];
    double y = data[2] * vec.data[0] - data[0] * vec.data[2];
    double z = data[0] * vec.data[1] - data[1] * vec.data[0];

    MyVector<Type> new_MyVector(3, x, y, z);
    return new_MyVector;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::multiplyVecToVector(const MyVector<Type>& vec)
{
    if (countElem != 3)
        return MyVector<Type>();

    double x = data[1] * vec.data[2] - data[2] * vec.data[1];
    double y = data[2] * vec.data[0] - data[0] * vec.data[2];
    double z = data[0] * vec.data[1] - data[1] * vec.data[0];

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
size_t MyVector<Type>::size() const
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
MyVector<Type> MyVector<Type>::sumMyVectors(const MyVector<Type>& vec2) const
{
    MyIterator<Type> iter_vec1(*this);
    MyIterator<Type> iter_vec2(vec2);

    int max_len = max(countElem, vec2.countElem);
    MyVector<Type> result(max_len);

    MyIterator<Type> iter_result(result);

    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= countElem)
            *iter_result = *iter_vec2;
        else if (i >= vec2.countElem)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 + *iter_vec2;
    }

    return result;
}

template <typename Type>
MyVector<Type> MyVector<Type>::differenceMyVectors(const MyVector<Type>& vec2) const
{
    MyIterator<Type> iter_vec1(*this);
    MyIterator<Type> iter_vec2(vec2);

    int max_len = max(countElem, vec2.countElem);
    MyVector<Type> result(max_len);

    MyIterator<Type> iter_result(result);

    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= countElem)
            *iter_result = -*iter_vec2;
        else if (i >= vec2.countElem)
            *iter_result = *iter_vec1;
        else
            *iter_result = *iter_vec1 - *iter_vec2;
    }

    return result;
}

template <typename Type>
MyVector<Type> MyVector<Type>::multMyVectors(const MyVector<Type>& vec2) const
{
    MyIterator<Type> iter_vec1(*this);
    MyIterator<Type> iter_vec2(vec2);

    int max_len = max(countElem, vec2.countElem);
    MyVector<Type> result(max_len);

    MyIterator<Type> iter_result(result);

    for (int i = 0; iter_result; i++, iter_result++, iter_vec1++, iter_vec2++)
    {
        if (i >= countElem || i >= vec2.countElem)
            *iter_result = 0;
        else
            *iter_result = *iter_vec1 * *iter_vec2;
    }

    return result;
}

template <typename Type>
MyVector<Type> MyVector<Type>::operator -() const
{
    MyVector<Type> new_MyVector(*this);
    MyIterator<Type> iter(new_MyVector);
    for (; iter; iter++)
        *iter = -*iter;

    return new_MyVector;
}

template<typename Type>
MyVector<Type>& MyVector<Type>::multiplyToNumber(const Type& value)
{
    MyIterator<Type> iter(*this);

    for (; iter; iter++)
        *iter *= value;

    return *this;
}

template <typename Type>
MyIterator<Type> MyVector<Type>::begin()
{
    MyIterator<Type> it(*this);
    return it;
}

template <typename Type>
MyIterator<Type> MyVector<Type>::end()
{
    return MyIterator<Type>(*this, size());
}

template <typename Type>
void MyVector<Type>::allocMemory(int countElem)
{
    data.reset();
    shared_ptr<Type[]> sp_temp(new Type[countElem], default_delete<Type[]>());
    data = sp_temp;
}
#pragma once

#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <stdexcept>

#include "MyBaseVector.h"
#include "MyIterator.cpp"
#include "Errors.h"

#define EPS 1e-5

using namespace std;

template<typename Type>
class MyVector : public MyBaseVector
{
public:
    friend class MyIterator<Type>;

    MyVector();
    explicit MyVector(int countElem);
    MyVector(int countElem, Type* vec);
    MyVector(int countElem, Type vec, ...);
    MyVector(initializer_list<Type> args);
    explicit MyVector(const MyVector<Type>& vec);
    MyVector(MyVector<Type>&& vec);
    ~MyVector();

    MyVector<Type>& operator =(const MyVector<Type>& vec);
    MyVector<Type>& operator =(MyVector<Type>&& vec);
    MyVector<Type>& operator =(initializer_list<Type> args);

    bool isZero() const;
    bool isSingle() const;
    int size() const;
    Type len() const;

    Type& operator[](int index);
    const Type& operator[](int index) const;

    Type& getElemMyVector(int index);
    const Type& getElemMyVector(int index) const;
    bool setElemMyVector(int index, const Type& vec);
    MyVector<Type> getSingleMyVector() const;

    MyVector<Type>& operator *=(const Type& mult);
    MyVector<Type>& operator /=(const Type& div);
    MyVector<Type> operator -();

    Type operator *(const MyVector<Type>& vec) const;
    MyVector<Type>& operator &=(const MyVector<Type>& vec);
    MyVector<Type> operator &(const MyVector<Type>& vec) const;
    MyVector<Type> operator +(const MyVector<Type>&) const;
    MyVector<Type>& operator +=(const MyVector<Type>&);
    MyVector<Type> operator -(const MyVector<Type>&) const;
    MyVector<Type>& operator -=(const MyVector<Type>&);

    double angleBetweenMyVectors(const MyVector<Type>&) const;
    bool isCollinearity(const MyVector<Type>&) const;
    bool isOrthogonality(const MyVector<Type>&) const;

    bool operator ==(const MyVector<Type>&) const;
    bool operator !=(const MyVector<Type>&) const;

protected:
    Type sumAllElem();
    void sumMyVectors(MyVector<Type>& result, const MyVector<Type>& vec1, const MyVector<Type>& vec2) const;
    void differenceMyVectors(MyVector<Type>& result, const MyVector<Type>& vec1, const MyVector<Type>& vec2) const;
    void multMyVectors(MyVector<Type>& result, const MyVector<Type>& vec1, const MyVector<Type>& vec2) const;
    void allocMemory(int);

private:
    shared_ptr<Type> data;
    int countElem;
};

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

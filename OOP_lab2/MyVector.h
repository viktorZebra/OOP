#pragma once
#pragma warning(disable : 4996)

#include <stdarg.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <time.h>
#include <stdexcept>

#include "MyBaseVector.h"
#include "MyIterator.hpp"
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
    size_t size() const; // size_t (����������)
    Type len() const;

    Type& operator[](int index);
    const Type& operator[](int index) const;

    Type& getElemMyVector(int index);
    const Type& getElemMyVector(int index) const;
    bool setElemMyVector(int index, const Type& vec);
    MyVector<Type> getSingleMyVector() const;

    MyVector<Type>& operator *(const Type& mult);
    MyVector<Type>& operator *=(const Type& mult);
    MyVector<Type>& multiplyToNumber(const Type& value); // ������� ��������� �� �����

    MyVector<Type>& operator /=(const Type& div);
    MyVector<Type>& operator /(const Type& div);
    MyVector<Type>& divToNumber(const Type& div); // ������� ������� ������� �� ����� (��������� �� ��������)

    MyVector<Type> operator -() const; // (����������)

    Type operator *(const MyVector<Type>& vec) const;
    Type operator *=(const MyVector<Type>& vec) const;
    MyVector<Type>& multiplyScalToVector(const MyVector<Type>& vec); // ������� ��������� ��������� 

    MyVector<Type>& operator &=(const MyVector<Type>& vec);
    MyVector<Type> operator &(const MyVector<Type>& vec) const; 
    MyVector<Type>& multiplyVecToVector(const MyVector<Type>& vec); // ������� ��������� ��������� 

    MyVector<Type> operator +(const MyVector<Type>&) const; 
    MyVector<Type>& operator +=(const MyVector<Type>&); 
    MyVector<Type> sumMyVectors(const MyVector<Type>& vec2) const; // ������� ����� ���� ��������

    MyVector<Type> operator -(const MyVector<Type>&) const;
    MyVector<Type> operator -=(const MyVector<Type>&);
    MyVector<Type> differenceMyVectors(const MyVector<Type>& vec2) const; // ������� ������� ���� �������� 

    Type angleBetweenMyVectors(const MyVector<Type>&) const; // ��� ������� ������������ (����������)
    bool isCollinearity(const MyVector<Type>&) const;
    bool isOrthogonality(const MyVector<Type>&) const;

    bool operator ==(const MyVector<Type>& vec) const;
    bool operator !=(const MyVector<Type>&) const;

    MyIterator<Type> begin();
    MyIterator<Type> end();

protected:
    void allocMemory(int);
    MyVector<Type> multMyVectors(const MyVector<Type>& vec2) const;
    Type sumAllElem();

private:
    shared_ptr<Type[]> data; // ��������� [] (����������)
    int countElem;
};

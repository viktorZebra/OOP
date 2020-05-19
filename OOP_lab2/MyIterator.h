#pragma once
#include <iostream>
#include <memory>
#include <iterator>
#include <initializer_list>
#include <ctime>
#include "Errors.h"

#include "MyBaseIterator.h"

using namespace std;

template<class Type>
class MyVector;

template<typename Type>
class MyIterator : public MyBaseIterator , public std::iterator <std::input_iterator_tag, Type>
{
public:
    MyIterator(const MyIterator<Type>& other);
    MyIterator(const MyVector<Type>& vector);

    Type& operator*();
    const Type& operator*() const;
    Type* operator->();
    const Type* operator->() const;
    operator bool() const;

    MyIterator<Type>& operator=(const MyIterator<Type>& other);
    MyIterator<Type>& operator=(Type value);

    MyIterator<Type>& operator++();
    MyIterator<Type> operator++(int);

    bool operator==(const MyIterator<Type>& other) const;
    bool operator!=(const MyIterator<Type>& other) const;

private:
    weak_ptr<Type[]> dataPtr;
    bool IsNullPointer(int string) const;
};



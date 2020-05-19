#pragma once

#include <iostream>
#include <memory>
#include "MyBaseIterator.h"
#include <ctime>
#include <iterator>
#include "Errors.h"


template<class Type>
class MyVector;

template <typename DataType>
class IteratorConst : public MyBaseIterator, public std::iterator <std::input_iterator_tag, DataType>
{
public:
    IteratorConst(const IteratorConst<DataType>& iter);
    IteratorConst(const MyVector<DataType>& vec, size_t index = 0);

    const DataType& operator*() const;
    const DataType* operator->() const;

    operator bool() const;

    IteratorConst<DataType>& operator=(const IteratorConst<DataType>& iter);

    IteratorConst<DataType>& operator+=(int n);
    IteratorConst<DataType> operator+(int n);
    IteratorConst<DataType>& operator++();
    IteratorConst<DataType> operator++(int);

    IteratorConst<DataType>& operator-=(int n);
    IteratorConst<DataType> operator-(int n);
    IteratorConst<DataType>& operator--();
    IteratorConst<DataType> operator--(int);

    bool operator<=(const IteratorConst<DataType>& b) const;
    bool operator<(const IteratorConst<DataType>& b) const;
    bool operator>=(const IteratorConst<DataType>& b) const;
    bool operator>(const IteratorConst<DataType>& b) const;
    bool operator==(const IteratorConst<DataType>& b) const;
    bool operator!=(const IteratorConst<DataType>& b) const;

    bool control(int string) const;

private:
    std::weak_ptr<DataType[]> ptr;

};

template <typename DataType>
IteratorConst<DataType>::IteratorConst(const MyVector<DataType>& vec, size_t index)
{
    this->num_elem = vec._size;
    this->ptr = vec.coords;
    this->position = index;
}

template <typename DataType>
IteratorConst<DataType>::IteratorConst(const IteratorConst<DataType>& iter)
{
    this->ptr = iter.ptr;
    this->position = iter.position;
    this->num_elem = iter.num_elem;
}


template <typename DataType>
const DataType& IteratorConst<DataType>::operator*() const
{
    control(__LINE__);

    auto thisPtr = this->ptr.lock();

    DataType* rawData = thisPtr.get();
    DataType* pointedData = rawData + this->position;

    return *(pointedData);
}

template <typename DataType>
const DataType* IteratorConst<DataType>::operator->() const
{
    control(__LINE__);

    auto thisPtr = this->ptr.lock();

    DataType* rawData = thisPtr.get();
    DataType* pointedData = rawData + this->position;
    return pointedData;
}

template <typename DataType>
IteratorConst<DataType>::operator bool() const
{
    control(__LINE__);

    auto thisPtr = this->num_elem.lock();
    if (position >= *thisPtr || position < 0 || (*thisPtr == 0))
        return false;
    else
        return true;
}


template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator=(const IteratorConst<DataType>& iter)
{
    control(__LINE__);

    ptr = iter.ptr;
    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator+=(int n)
{
    control(__LINE__);
    this->position += n;

    return *this;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator+(int n)
{
    control(__LINE__);
    IteratorConst<DataType> iter(*this);
    iter += n;

    return iter;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator++(int)
{
    control(__LINE__);
    ++(*this);

    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator++()
{
    control(__LINE__);
    ++position;

    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator-=(int n)
{
    control(__LINE__);
    position -= n;

    return *this;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator-(int n)
{
    control(__LINE__);

    IteratorConst<DataType> iter(*this);
    iter.position = this->position - n;

    return iter;
}

template <typename DataType>
IteratorConst<DataType> IteratorConst<DataType>::operator--(int)
{
    control(__LINE__);
    --(*this);

    return *this;
}

template <typename DataType>
IteratorConst<DataType>& IteratorConst<DataType>::operator--()
{
    control(__LINE__);
    --position;

    return *this;
}

template <typename DataType>
bool IteratorConst<DataType>::operator<=(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr <= b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator<(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr < b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator>=(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr >= b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator>(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr > b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator==(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr == b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::operator!=(const IteratorConst<DataType>& b) const
{
    control(__LINE__);

    return ptr != b.ptr;
}

template <typename DataType>
bool IteratorConst<DataType>::control(int string) const
{
    if (!ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw DeletedObj(__FILE__, string, ctime(&t_time));
    return false;
}


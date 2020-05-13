#include "MyIterator.h"

template<typename Type>
MyIterator<Type>::MyIterator(const MyIterator<Type>& other)
{
	index = other.index;
	countElem = other.countElem;
	dataPtr = other.dataPtr;
}

template<typename Type>
MyIterator<Type>::MyIterator(const MyVector<Type>& other)
{
	index = 0;
	dataPtr = other.data;
	countElem = other.countElem;
}

template<typename Type>
Type& MyIterator<Type>::operator*()
{
	shared_ptr<Type> bufPtr = dataPtr.lock();

	return *(bufPtr.get() + index);
}

template<typename Type>
const Type& MyIterator<Type>::operator*() const
{
	shared_ptr<Type> bufPtr(dataPtr);

	return bufPtr[index];
}

template<typename Type>
Type* MyIterator<Type>::operator->()
{
	shared_ptr<Type> bufPtr(dataPtr);

	return bufPtr.get() + index;
}

template<typename Type>
const Type* MyIterator<Type>::operator->() const
{
	shared_ptr<Type> bufPtr(dataPtr);

	return bufPtr.get() + index;
}

template<typename Type>
MyIterator<Type>::operator bool() const
{
	if (index < 0 || index >= countElem || countElem == 0)
		return false;
	else
		return true;
}

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator=(const MyIterator<Type>& other)
{
	//проверка на самоприсваивание
	if (this == &other) 
	{
		return *this;
	}

	dataPtr = other.dataPtr;
	countElem = other.countElem;
	index = other.index;

	return *this;
}

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator=(Type value)
{
	dataPtr[index] = value;

	return *this;
}

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator++()
{
	++index;

	return *this;
}

template<typename Type>
MyIterator<Type> MyIterator<Type>::operator++(int)
{
	++(*this);

	return *this;
}

template<class Type>
bool MyIterator<Type>::operator==(const MyIterator<Type>& other) const
{
	return dataPtr == other.dataPtr;
}

template<class Type>
bool MyIterator<Type>::operator!=(const MyIterator<Type>& other) const
{
	return dataPtr != other.dataPtr;
} 


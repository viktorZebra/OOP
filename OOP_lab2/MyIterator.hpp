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
	IsNullPointer(__LINE__);

	shared_ptr<Type[]> bufPtr = dataPtr.lock();

	return bufPtr[index];
}

template<typename Type>
const Type& MyIterator<Type>::operator*() const
{
	IsNullPointer(__LINE__);

	shared_ptr<Type[]> bufPtr = dataPtr.lock();

	return bufPtr[index];
}

template<typename Type>
Type* MyIterator<Type>::operator->() // исключение (исправил)
{
	IsNullPointer(__LINE__);

	shared_ptr<Type[]> bufPtr = dataPtr.lock();

	return bufPtr.get() + index;
}

template<typename Type>
const Type* MyIterator<Type>::operator->() const
{
	IsNullPointer(__LINE__);

	shared_ptr<Type[]> bufPtr = dataPtr.lock();

	return bufPtr.get() + index;
}

template<typename Type>
MyIterator<Type>::operator bool() const
{
	IsNullPointer(__LINE__);

	if (index < 0 || index >= countElem || countElem == 0)
		return false;
	else
		return true;
}

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator=(const MyIterator<Type>& other)
{
	IsNullPointer(__LINE__);

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
	IsNullPointer(__LINE__);

	dataPtr[index] = value;

	return *this;
}

template<typename Type>
MyIterator<Type>& MyIterator<Type>::operator++()
{
	IsNullPointer(__LINE__);

	++index;

	return *this;
}

template<typename Type>
MyIterator<Type> MyIterator<Type>::operator++(int)
{
	IsNullPointer(__LINE__);

	++(*this);

	return *this;
}

template<class Type>
bool MyIterator<Type>::operator==(const MyIterator<Type>& other) const
{
	IsNullPointer(__LINE__);

	return dataPtr == other.dataPtr;
}

template<class Type>
bool MyIterator<Type>::operator!=(const MyIterator<Type>& other) const
{
	IsNullPointer(__LINE__);

	return dataPtr != other.dataPtr;
} 

template <typename Type>
bool MyIterator<Type>::IsNullPointer(int string) const
{
	if (!dataPtr.expired())
		return true;

	time_t t_time = time(NULL);
	throw DeletedObj(__FILE__, string, ctime(&t_time));
	return false;
}

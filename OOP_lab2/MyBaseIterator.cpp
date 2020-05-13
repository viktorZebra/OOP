#include "MyBaseIterator.h"

MyBaseIterator::MyBaseIterator()
{
	index = 0;
	countElem = 0;
}

MyBaseIterator::MyBaseIterator(const MyBaseIterator& other)
{
	index = other.index;
	countElem = other.countElem;
}

MyBaseIterator::~MyBaseIterator() { }
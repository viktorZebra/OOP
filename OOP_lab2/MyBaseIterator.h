#pragma once

class MyBaseIterator
{
public:
	MyBaseIterator();
	MyBaseIterator(const MyBaseIterator& other);
	virtual ~MyBaseIterator() = 0;
protected:
	int index;
	int countElem;
};

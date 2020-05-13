#pragma once

class MyBaseIterator
{
public:
	MyBaseIterator();
	MyBaseIterator(const MyBaseIterator& other);
	~MyBaseIterator();
protected:
	int index;
	int countElem;
};

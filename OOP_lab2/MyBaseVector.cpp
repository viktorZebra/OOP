#include <stdio.h>
#include "MyBaseVector.h"

MyBaseVector::MyBaseVector()
{
    countElem = 0;
}

MyBaseVector::MyBaseVector(const MyBaseVector& other)
{
    countElem = other.countElem;
}

MyBaseVector::~MyBaseVector() { }

int MyBaseVector::getSize() const 
{
    return countElem;
}

bool MyBaseVector::isEmpty() const 
{
    return !countElem;
}
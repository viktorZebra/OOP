#pragma once

template<typename Type>
class MyIterator;

class MyBaseVector {
public:
    MyBaseVector();
    MyBaseVector(const MyBaseVector&);
    virtual ~MyBaseVector() = 0;

    bool isEmpty() const;
    int getSize() const;

protected:
    int countElem;
};

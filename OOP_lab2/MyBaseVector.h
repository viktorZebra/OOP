#pragma once

template<typename Type>
class MyIterator;

class MyBaseVector {
public:
    MyBaseVector();
    MyBaseVector(const MyBaseVector&);
    ~MyBaseVector();

    bool isEmpty() const;
    int getSize() const;

protected:
    int countElem;
};

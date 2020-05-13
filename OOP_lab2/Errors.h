#ifndef _errors_h
#define _errors_h

#include <exception>
#include <string>
#include <iostream>

class ExceptionVector : public std::exception
{
protected:
    char* errorMsg;
public:
    ExceptionVector(const char* msg)
    {
        int Len = strlen(msg) + 1;
        this->errorMsg = new char[Len];
        strcpy_s(this->errorMsg, Len, msg);
    }

    virtual ~ExceptionVector() 
    {
        delete[] errorMsg; 
    }

    virtual const char* what() const noexcept override 
    { 
        return this->errorMsg;
    }
};

class MemError : public ExceptionVector
{
private:
    const char* errMemMsg = "Memory error";

public:
    MemError(const char* msg) : ExceptionVector(msg) {}
    virtual ~MemError() {}

    virtual const char* what() const noexcept
    {
        int Len = strlen(errorMsg) + strlen(errMemMsg) + 8;

        char* buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s %s", errorMsg, errMemMsg);

        const_cast<MemError*>(this)->errorMsg = buff;

        return errorMsg;
    }
};

class EmptyError : public ExceptionVector
{
private:
    const char* errEmptyMsg = "Try to use empty vector";
public:
    EmptyError(const char* msg) : ExceptionVector(msg) {}
    virtual ~EmptyError() {}

    virtual const char* what() const noexcept override
    {
        int Len = strlen(errorMsg) + strlen(errEmptyMsg) + 8;

        char* buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s %s", errorMsg, errEmptyMsg);

        const_cast<EmptyError*>(this)->errorMsg = buff;

        return errorMsg;
    }
};

class IndexError : public ExceptionVector
{
private:
    const char* errIndexMsg = "Error Index";
    int ind;
public:
    IndexError(const char* msg, int index) : ExceptionVector(msg), ind(index) {}
    virtual ~IndexError() {}

    virtual const char* what() const noexcept override
    {
        int Len = strlen(errorMsg) + strlen(errIndexMsg) + 8;

        char* buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s %s: %4d", errorMsg, errIndexMsg, ind);

        const_cast<IndexError*>(this)->errorMsg = buff;

        return errorMsg;
    }
};


class ZeroDivError : public ExceptionVector
{
private:
    const char* errZeroDivMsg = "Zero division error";
public:
    ZeroDivError(const char* msg) : ExceptionVector(msg) {}
    virtual ~ZeroDivError() {}

    virtual const char* what() const noexcept
    {
        int Len = strlen(errorMsg) + strlen(errZeroDivMsg) + 8;

        char* buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s %s", errorMsg, errZeroDivMsg);

        const_cast<ZeroDivError*>(this)->errorMsg = buff;

        return errorMsg;
    }
};

class DeletedObj : public ExceptionVector
{
private:
    const char* errZeroDivMsg = "Work with deleted object";
public:
    DeletedObj(const char* msg) : ExceptionVector(msg) {};
    virtual ~DeletedObj() {}

    virtual const char* what() const noexcept
    {
        int Len = strlen(errorMsg) + strlen(errZeroDivMsg) + 8;

        char* buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s %s", errorMsg, errZeroDivMsg);

        const_cast<DeletedObj*>(this)->errorMsg = buff;

        return errorMsg;
    }
};

#endif /* _errors_h */

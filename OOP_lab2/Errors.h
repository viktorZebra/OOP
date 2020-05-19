#ifndef _errors_h
#define _errors_h

#include <exception>
#include <string>
#include <iostream>

class ExceptionVector : public std::exception
{
public:
    ExceptionVector(std::string filename, int line, const char* time,
        std::string info = "Error")
    {
        message_error = "\nFile name: " + filename + "\nLine#: " + std::to_string(line) +
            "\nTime: " + time + "Info: " + info;
    }
    virtual const char* what() const noexcept override
    {
        return message_error.c_str();
    }
protected:
    std::string message_error;
};

class MemError : public ExceptionVector // время строка (исправлено)
{
public:
    MemError(std::string filename, int line, const char* time,
        std::string info = "Memory error") : ExceptionVector(filename, line, time, info) {}
    virtual ~MemError() {}
};

class EmptyError : public ExceptionVector
{
public:
    EmptyError(std::string filename, int line, const char* time,
        std::string info = "Try to use empty vector") : ExceptionVector(filename, line, time, info) {}
    virtual ~EmptyError() {}
};

class IndexError : public ExceptionVector
{
public:
    IndexError(std::string filename, int line, const char* time,
        std::string info = "Index error") : ExceptionVector(filename, line, time, info) {}
    virtual ~IndexError() {}
};


class ZeroDivError : public ExceptionVector
{
private:
    const char* errZeroDivMsg = "Zero division error";
public:
    ZeroDivError(std::string filename, int line, const char* time,
        std::string info = "Zero division error") : ExceptionVector(filename, line, time, info) {}
    virtual ~ZeroDivError() {}
};

class DeletedObj : public ExceptionVector
{
private:
    const char* errZeroDivMsg = "Work with deleted object";
public:
    DeletedObj(std::string filename, int line, const char* time,
        std::string info = "Work with deleted object") : ExceptionVector(filename, line, time, info) {};
    virtual ~DeletedObj() {}
};

#endif /* _errors_h */

#ifndef NOINSTANCEFOUNDEXCEPTION_HPP
#define NOINSTANCEFOUNDEXCEPTION_HPP

#include <iostream>
#include <string>
#include <cstring>
class NoInstanceFoundException : public std::exception
{
private:
    char *_msg;

public:
    NoInstanceFoundException() = delete;
    explicit NoInstanceFoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    NoInstanceFoundException(const NoInstanceFoundException &) = default;
    NoInstanceFoundException(NoInstanceFoundException &&) = delete;
    NoInstanceFoundException &operator=(NoInstanceFoundException &&) = delete;
    NoInstanceFoundException &operator=(const NoInstanceFoundException &) = default;
    ~NoInstanceFoundException() = default;
    virtual const char *what()
    {
        return _msg;
    };
};

#endif // NOINSTANCEFOUNDEXCEPTION_HPP

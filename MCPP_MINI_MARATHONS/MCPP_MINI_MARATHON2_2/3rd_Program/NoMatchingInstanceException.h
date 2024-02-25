





#ifndef NOMATCHINGINSTANCEEXCEPTION_H
#define NOMATCHINGINSTANCEEXCEPTION_H

#include <iostream>
#include <cstring>
class NoMatchingInstanceException : public std::exception
{
private:
    char *_msg;

public:
    NoMatchingInstanceException() = delete;
    NoMatchingInstanceException(const NoMatchingInstanceException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    NoMatchingInstanceException(NoMatchingInstanceException &&) = default;
    NoMatchingInstanceException &operator=(const NoMatchingInstanceException &) = default;
    NoMatchingInstanceException &operator=(NoMatchingInstanceException &&) = default;

    NoMatchingInstanceException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    virtual const char *what()
    {
        return _msg;
    }

    ~NoMatchingInstanceException()
    {
        delete _msg;
    }
};







#endif // NOMATCHINGINSTANCEEXCEPTION_H












































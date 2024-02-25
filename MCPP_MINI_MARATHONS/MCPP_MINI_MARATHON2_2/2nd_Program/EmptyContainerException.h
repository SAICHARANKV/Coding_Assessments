



#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <iostream>
#include <cstring>
class EmptyContainerException : public std::exception
{
private:
    char *_msg;

public:
    EmptyContainerException() = delete;
    EmptyContainerException(const EmptyContainerException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    EmptyContainerException(EmptyContainerException &&) = default;
    EmptyContainerException &operator=(const EmptyContainerException &) = default;
    EmptyContainerException &operator=(EmptyContainerException &&) = default;

    EmptyContainerException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    virtual const char *what()
    {
        return _msg;
    }

    ~EmptyContainerException()
    {
        delete _msg;
    }
};





#endif // EMPTYCONTAINEREXCEPTION_H

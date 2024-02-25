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
    EmptyContainerException(const EmptyContainerException &e)
    {
        _msg = new char[strlen(e._msg) + 1];
        strcpy(_msg, e._msg);
    }
    EmptyContainerException &operator=(const EmptyContainerException &e)
    {
        _msg = new char[strlen(e._msg) + 1];
        strcpy(_msg, e._msg);
        return *this;
    }
    EmptyContainerException(EmptyContainerException &&e)
    {
        _msg = new char[strlen(e._msg) + 1];
        strcpy(_msg, e._msg);
    }
    EmptyContainerException &operator=(EmptyContainerException &&e)
    {
        _msg = new char[strlen(e._msg) + 1];
        strcpy(_msg, e._msg);
        return *this;
    }
    ~EmptyContainerException()
    {
        delete _msg;
    }

    explicit EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }

    const char *what()
    {
        return _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H

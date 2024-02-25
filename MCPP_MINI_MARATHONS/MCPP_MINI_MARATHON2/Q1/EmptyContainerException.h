#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <cstring>
#include <iostream>
#include <stdexcept>


class EmptyContainerException : public std::exception
{ 
private:
    char * _msg;

public:
    EmptyContainerException() = delete;
    EmptyContainerException(const EmptyContainerException&) = delete;
    EmptyContainerException& operator=(const EmptyContainerException&) = delete;
    EmptyContainerException(EmptyContainerException&&)= delete;
    EmptyContainerException& operator=(EmptyContainerException&&) = delete;
    
    EmptyContainerException(const char* msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg,msg);
    }

    virtual const char * what() { return _msg;} 

    ~EmptyContainerException() 
    {
        delete _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H

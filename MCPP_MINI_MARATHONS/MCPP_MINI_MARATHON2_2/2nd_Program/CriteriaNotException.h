





#ifndef CRITERIANOTEXCEPTION_H
#define CRITERIANOTEXCEPTION_H

#include <iostream>
#include <cstring>
class CriteriaNotException : public std::exception
{
private:
    char *_msg;

public:
    CriteriaNotException() = delete;
    CriteriaNotException(const CriteriaNotException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    CriteriaNotException(CriteriaNotException &&) = default;
    CriteriaNotException &operator=(const CriteriaNotException &) = default;
    CriteriaNotException &operator=(CriteriaNotException &&) = default;

    CriteriaNotException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    virtual const char *what()
    {
        return _msg;
    }

    ~CriteriaNotException()
    {
        delete _msg;
    }
};






#endif // CRITERIANOTEXCEPTION_H

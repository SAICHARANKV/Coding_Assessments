
#ifndef FUNCTIONCONTAINEREXCEPTION_H
#define FUNCTIONCONTAINEREXCEPTION_H

#include<iostream>
#include<cstring>

class FunctionConatinerException:public std::exception
{
private:
    char* _msg;
public:
FunctionConatinerException()=delete;
FunctionConatinerException(const FunctionConatinerException& e)
{
    _msg=new char[strlen(e._msg)+1];
    strcpy(_msg,e._msg);
}
FunctionConatinerException& operator=(const FunctionConatinerException& e)
{
    _msg=new char[strlen(e._msg)+1];
    strcpy(_msg,e._msg);
     return *this;

}
FunctionConatinerException(FunctionConatinerException&& e)
{
    _msg=new char[strlen(e._msg)+1];
    strcpy(_msg,e._msg);
}
FunctionConatinerException& operator=(FunctionConatinerException&& e)
{
    _msg=new char[strlen(e._msg)+1];
    strcpy(_msg,e._msg);
     return *this;

}
~FunctionConatinerException()
{
    delete _msg;
}

explicit FunctionConatinerException(const char* msg)
{
    _msg=new char[strlen(msg)+1];
    strcpy(_msg,msg);
}

const char* what()
{
    return _msg;
}
};



#endif // FUNCTIONCONTAINEREXCEPTION_H
#ifndef DATASIZEEXCEPTION_HPP
#define DATASIZEEXCEPTION_HPP

#include <iostream>
#include <string>
#include <cstring>
class DataSizeException : public std::exception
{
private:
    char *_msg;

public:
    DataSizeException() = delete;
    explicit DataSizeException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    DataSizeException(const DataSizeException &) = default;
    DataSizeException(DataSizeException &&) = delete;
    DataSizeException &operator=(DataSizeException &&) = delete;
    DataSizeException &operator=(const DataSizeException &) = default;
    ~DataSizeException() = default;
    virtual const char *what()
    {
        return _msg;
    };
};

#endif // DATASIZEEXCEPTION_HPP

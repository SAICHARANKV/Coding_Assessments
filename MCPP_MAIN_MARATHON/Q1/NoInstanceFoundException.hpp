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
    NoInstanceFoundException &operator=(const NoInstanceFoundException &) = default;
    NoInstanceFoundException(NoInstanceFoundException &&) = default;
    NoInstanceFoundException &operator=(NoInstanceFoundException &&) = delete;
    ~NoInstanceFoundException() = default;

    virtual const char *what() { return _msg; }
};
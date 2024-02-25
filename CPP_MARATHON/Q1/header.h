#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
class user
{
    std::string userid;
    std::string username;
    std::string department;

public:
    user();
    user(std::string, std::string, std::string);

    std::string getUserid() const { return userid; }
    void setUserid(const std::string &userid_) { userid = userid_; }

    std::string getUsername() const { return username; }
    void setUsername(const std::string &username_) { username = username_; }

    std::string getDepartment() const { return department; }
    void setDepartment(const std::string &department_) { department = department_; }

    friend void istream(std::istream &is, user &u);

    bool operator==(const user &u);

    void accept();
};

class nouserexpection : public std::exception
{
    char message[100];

public:
    nouserexpection()
    {
        std::cout << "User not found";
    }
    nouserexpection(const char *msg)
    {
        strcpy(message, msg);
    }
    char *what()
    {
        std::cout << "No department matched with other" << std::endl;
    }
};
void count(user[]);

#endif // HEADER_H

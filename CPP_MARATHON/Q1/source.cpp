#include <iostream>
#include "header.h"

user::user()
{
    userid = "1";
    username = "Sai";
    department = "COM";
}

user::user(std::string id, std::string name, std::string dept)
{
    userid = id;
    username = name;
    department = dept;
}

void istream(std::istream &is, user &u)
{
    is >> u.userid;
    is >> u.username;
    is >> u.department;
}
bool user::operator==(const user &u)
{
    if (this->department == u.department)
        return true;
    return false;
}

void user::accept()
{
    std::cout << "Enter id";
    std::cin >> userid;
    std::cout << "Enter User name";
    std::cin >> username;
    std::cout << "Enter User department";
    std::cin >> department;
}

void count(user a[])
{
    int count = 0;
    std::string ele;
    std::cout << "Enter department name to be counted";
    std::cin >> ele;
    for (int i = 0; i < 3; i++)
    {
        if (a[i].getDepartment() == ele)
            count++;
    }
    if (count > 0)
        std::cout << "The number of people with department " << ele << " are " << count << std::endl;
    else
        throw nouserexpection("No User found");
}

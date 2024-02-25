#include <iostream>
#include "header.h"

int main()
{
    user a[3];
    for (int i = 0; i < 3; i++)
    {
        a[i].accept();
    }
    try
    {
        count(a);
    }
    catch (nouserexpection n)
    {
        std::cout << n.what()<< std::endl;
    }
    user obj1("1", "sai", "com");
    user obj2("2", "charan", "cse");
    std::cout << (obj1 == obj2 ? "Equal" : "Not Equal");

    user obj3("2", "charan", "cse");
    obj3;
}
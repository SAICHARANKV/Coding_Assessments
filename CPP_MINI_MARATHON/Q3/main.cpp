#include <iostream>
#include "header.h"

int main()
{
    Player a1;
    a1.display();
    int n = 2;
    Player a[n];
    for (int i = 0; i < 2; i++)
    {
        a[i].accept();
    }
    for (int i = 0; i < 2; i++)
    {
        a[i].display();
    }
    Player obj1, obj2;
    std::cout << "Operator == :\t" << (obj1 == obj2 ? "Equal" : "Not Equal") << std::endl;
    std::cout << "Operator < :\t" << (obj1 < obj2 ? "True" : "False") << std::endl;
    std::cout << "Operator [] :\t" << obj1[33] << std::endl;
    std::cout << "Operator << :\t" << obj1 << std::endl;

    return 0;
}
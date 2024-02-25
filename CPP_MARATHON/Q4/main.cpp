#include <iostream>
#include "header.h"

int main()
{
    int n;
    std::cout << "No of objects\n";
    std::cin >> n;
    Hospital *s = new Hospital[n];
    for (int i = 0; i < n; i++)
    {
        s[i].accept();
    }

    Hospital *d = new doctor[n];
    for (int i = 0; i < n; i++)
    {
        d[i].accept();
    }
    Hospital obj1;
    std::cout<<obj1;
    
    }
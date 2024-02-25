#include <iostream>
#include "header.h"
#include <cstring>

int main()
{
    Book a1;
    a1.display();
    int n = 3;
    Book a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].accept();
    }

    for (int i = 0; i < n; i++)
    {
        a[i].display();
    }
    std::cout<<"Author with letter A\n";
    findauthor(a, n);
    std::cout << "\nBook less than 2500\n";
    lessbooks(a, n);
    return 0;
}
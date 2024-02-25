#include <iostream>
#include "header.h"

int main()
{
    int n;
    std::cout << "Enter Number of Objects\n";
    std::cin >> n;

    Loan *lptr = new Loan[n];
    int choice, count = 0, i = 0;

    do
    {
        std::cout << "Loan Management System\n";
        std::cout << "1. Adding One Record\n";
        std::cout << "2. Show All\n";
        std::cout << "3. Search Record\n";
        std::cout << "4. Count Record\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter Your choice\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            count++;
            lptr[i].add();
            i++;
            break;
        case 2:
            if(count>0)
            {
            show(lptr, count);
            break;
            }
            else
                std::cout<<"No Records\n";
        case 3:
            search(lptr, count);
            break;
        case 4:
            countcustomers(lptr, count);
            break;
        case 5:
            std::cout << "Exiting Program\n";
            exit(0);
        default:
            std::cout << "Invalid Option\n";
        }
    } while (choice != 5);
    delete[] lptr;
    return 0;
}
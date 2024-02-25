#include <iostream>
#include "header.h"
#include <cstring>

// Default Constructor
Loan::Loan()
{
    Loanno = 0;
    Amount = 0;
    strcpy(Name, "Sunny");
    InterestAmount = 0;

    strcpy(Name, "Sunny");
}

// Parameterized Constructor
Loan::Loan(int lno, float amt, char s[], float iamt)
    : Loanno(lno), Amount(amt), InterestAmount(iamt)
{
    strcpy(Name, "sai");
}

float Loan::calculateinterest(int amt)
{
    if (amt > 0 && amt < 100000)
        return amt * (2 / 100);
    else if (amt > 100000 && amt < 500000)
        return amt * (5 / 100);
    else if (amt > 500000 && amt < 150000)
        return amt * (10 / 100);
    else
        return amt * (15 / 100);
}

void Loan::add()
{
    std::cout << "Enter Details\n";
    std::cout << "Loan Number:\t";
    std::cin >> Loanno;
    std::cout << "Amount:\t";
    std::cin >> Amount;
    std::cout << "Name:\t";
    std::cin >> Name;
    std::cout << "Interest Amount:\t";
    InterestAmount = calculateinterest(Amount);
}

void show(Loan a[], int size)
{
    std::cout << "Displaying Details\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Loan Number:\t" << a[i].loanno();
        std::cout << "Amount:\t" << a[i].amount();
        std::cout << "Name:\t" << a[i].name();
        std::cout << "Interest Amount:\t" << a[i].interestAmount();
    }
}

void search(Loan lptr[], int size)
{
    int num;
    std::cout << "Enter Loan Number to be searched\n";
    std::cin >> num;
    int flag = 1;
    for (int i = 0; i < size; i++)
    {
        if (num == lptr[i].loanno())
        {
            std::cout << "Record Found\n";
            flag = 0;
        }
    }
    if (flag != 0)
    {
        std::cout << "No Record Found\n";
    }
}

void countcustomers(Loan a[], int count)
{
    int ct = 1;
    int max = a[0].interestAmount();
    for (int i = 1; i < count; i++)
    {
        if (max < a[i].interestAmount())
        {
            max = a[i].interestAmount();
            ct++;
        }
    }

    std::cout << "Max Interest for loan num" << a[ct].loanno();
}
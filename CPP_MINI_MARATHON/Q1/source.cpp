#include <iostream>
#include "header.h"

void Book::accept()
{
    std::cout << "Enter Details\n";
    std::cout << "Book ID:\t";
    std::cin >> Bookid;

    std::cout << "Book Name:\t";
    std::cin >> Bookname;
    std::cout << "Author Name:\t";
    std::cin >> Authorname;
    std::cout << "Price:\t";
    std::cin >> price;
    std::cout << "Number of days used:\t";
    std::cin >> Numberofdaysused;
    calculateFine(Numberofdaysused);
}

void Book::display()
{
    std::cout << "Book Details\n";
    std::cout << "Id: " << Bookid << std::endl;
    std::cout << "Book Name: " << Bookname << std::endl;
    std::cout << "Author Name: " << Authorname << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "No of days used: " << Numberofdaysused << std::endl;
}

void Book::calculateFine(int days)
{
    if (days > 10 && days < 20)
    {
        std::cout << "Your Fine is 100rs\n";
    }
    if (days > 20 && days < 30)
    {
        std::cout << "Your Fine is 200rs\n";
    }
    if (days > 30 && days < 40)
    {
        std::cout << "Your Fine is 300rs\n";
    }
    if (days > 40)
    {
        std::cout << "Your Fine is 500rs\n";
    }
}

Book::Book()
{
    int id = 0;
    setBookid(id);
    char name[30] = "Sai";
    setBookname(name);
    char aname[30] = "Hello";
    setAuthorname(aname);
    int p = 1000;
    setPrice(p);
    int nd = 15;
    setNumberofdaysused(nd);
}

Book::Book(int b, char *bname, char *aname, int cost, int days) : Bookid(b), price(cost), Numberofdaysused(days)
{
    strcpy(Authorname, aname);
    strcpy(Bookname, bname);
}

void findauthor(Book a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        const char *s = a[i].authorname();
        if (s[0] == 'A' || s[0] == 'a')
        {
            std::cout << s << "\n";
            count++;
        }
    }
    if (count == 0)
        std::cout << "No authors found with the first letter 'A'\n";
}

void lessbooks(Book a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i].getPrice() < 2500)
        {
            std::cout << a[i].bookname() << "\n";
        }
    }
}
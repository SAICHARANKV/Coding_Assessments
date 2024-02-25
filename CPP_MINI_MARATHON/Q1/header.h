#ifndef HEADER_H
#define HEADER_H
#include <cstring>
class Book
{
private:
    int Bookid;

    int price;
    int Numberofdaysused;
    char Bookname[30];
    char Authorname[30];

public:
    Book();
    Book(int, char *, char *, int, int);

    void calculateFine(int days);

    void accept();

    void display();

    int bookid() const { return Bookid; }
    void setBookid(int bookid) { Bookid = bookid; }

    const char *bookname() { return Bookname; }
    void setBookname(const char *bookname) { strcpy(Bookname, bookname); }

    const char *authorname() { return Authorname; }
    void setAuthorname(const char *authorname) { strcpy(Authorname, authorname); }

    int getPrice() const { return price; }
    void setPrice(int price_) { price = price_; }

    int numberofdaysused() const { return Numberofdaysused; }
    void setNumberofdaysused(int numberofdaysused) { Numberofdaysused = numberofdaysused; }
};

void findauthor(Book a[], int n);
void lessbooks(Book a[], int n);

#endif // HEADER_H

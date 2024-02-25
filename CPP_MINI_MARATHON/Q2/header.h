#ifndef HEADER_H
#define HEADER_H

#include <cstring>
class Loan
{
    long int Loanno;
    float Amount;
    char Name[30];
    float InterestAmount;

public:
    Loan();
    Loan(int, float, char[], float);
    void add();
    float calculateinterest(int);

    long int loanno() const { return Loanno; }
    void setLoanno(long int loanno) { Loanno = loanno; }

    float amount() const { return Amount; }
    void setAmount(float amount) { Amount = amount; }

    char name() const { return *Name; }
    void setName(const char *name) { strcpy(Name, name); }

    float interestAmount() const { return InterestAmount; }
    void setInterestAmount(float interestAmount) { InterestAmount = interestAmount; }
};

void show(Loan[], int);
void search(Loan[], int);
void countcustomers(Loan[], int);

#endif // HEADER_H

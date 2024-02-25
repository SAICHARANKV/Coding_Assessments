#include "Bank.h"
int Bank::_id = 1;
Bank::Bank(int age)
    : person_age(age)
{
    _id++;
}

Bank::Bank(int age, float income)
    : Bank(age)
{
    person_income = income;
    _id++;
}
Bank::Bank(int age, float income, LoanIntentType intent)
    : Bank(age, income)
{
    loan_intent = intent;
    _id++;
}

Bank::Bank(int age, float income, LoanIntentType intent, float amt)
    : Bank(age, income, intent)
{
    loan_amount = amt;
    _id++;
}

Bank::Bank(int age, float income, LoanIntentType intent, float amt, float rate)
    : Bank(age, income, intent, amt)
{
    loan_int_rate = rate;
    _id++;
}

Bank::Bank(int age, float income, LoanIntentType intent, float amt, float rate, LoanStatusType status)
    : Bank(age, income, intent, amt, rate)
{
    loan_status = status;
    _id++;
}

std::ostream &operator<<(std::ostream &os, const Bank &rhs)
{
    os << " person_age: " << rhs.person_age
       << " person_income: " << rhs.person_income
       << " loan_intent: " << static_cast<int>(rhs.loan_intent)
       << " loan_amount: " << rhs.loan_amount
       << " loan_int_rate: " << rhs.loan_int_rate
       << " loan_status: " << static_cast<int>(rhs.loan_status);
    return os;
}

#ifndef BANK_H
#define BANK_H

#include "LoanIntentType.h"
#include "LoanStatusType.h"
#include <ostream>
class Bank
{
private:
    static int _id;
    int person_age{18};
    float person_income{0.0f};
    LoanIntentType loan_intent{LoanIntentType::EDUCATION};
    float loan_amount{0.0f};
    float loan_int_rate{0.0f};
    LoanStatusType loan_status{LoanStatusType::NO};

public:
    /*
   Special Enablers and disablers
   */
    Bank() = delete;
    Bank(const Bank &) = default;
    Bank &operator=(const Bank &) = default;
    Bank(Bank &&) = delete; // Move constructor
    Bank &operator=(Bank &&) = delete;
    ~Bank() = default;

    /*
    User Defined Parameterized constructors
    */
    Bank(int age);
    Bank(int age, float income);
    Bank(int age, float income, LoanIntentType intent);
    Bank(int age, float income, LoanIntentType intent, float amt);
    Bank(int age, float income, LoanIntentType intent, float amt, float rate);
    Bank(int age, float income, LoanIntentType intent, float amt, float rate, LoanStatusType status);

    /*
        Getters and Setters
    */

    static int id() { return Bank::_id; }

    int personAge() const { return person_age; }
    void setPersonAge(int personAge) { person_age = personAge; }

    float personIncome() const { return person_income; }
    void setPersonIncome(float personIncome) { person_income = personIncome; }

    LoanIntentType loanIntent() const { return loan_intent; }
    void setLoanIntent(const LoanIntentType &loanIntent) { loan_intent = loanIntent; }

    float loanAmount() const { return loan_amount; }
    void setLoanAmount(float loanAmount) { loan_amount = loanAmount; }

    float loanIntRate() const { return loan_int_rate; }
    void setLoanIntRate(float loanIntRate) { loan_int_rate = loanIntRate; }

    LoanStatusType loanStatus() const { return loan_status; }
    void setLoanStatus(const LoanStatusType &loanStatus) { loan_status = loanStatus; }

    friend std::ostream &operator<<(std::ostream &os, const Bank &rhs);
};

#endif // BANK_H

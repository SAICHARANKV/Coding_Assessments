#include <iostream>
#include <algorithm>
#include "Functionalities.h"
void CreateObjects(BankContainer &data)
{
    data.emplace_back(std::make_shared<Bank>(22, 59000.0f, LoanIntentType::PERSONAL, 35000.0f, 16.02f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(25, 9600.0f, LoanIntentType::MEDICAL, 5500.0f, 12.87f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(23, 65500.0f, LoanIntentType::MEDICAL, 35000.0f, 15.23f, LoanStatusType::NO));
    data.emplace_back(std::make_shared<Bank>(24, 54400.0f, LoanIntentType::MEDICAL, 35000.0f, 14.27f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(21, 9900.0f, LoanIntentType::VENTURE, 2500.0f, 7.14f, LoanStatusType::NO));
    data.emplace_back(std::make_shared<Bank>(26, 77100.0f, LoanIntentType::EDUCATION, 35000.0f, 12.42f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(24, 78956.0f, LoanIntentType::MEDICAL, 35000.0f, 11.11f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(24, 83000.0f, LoanIntentType::PERSONAL, 35000.0f, 8.9f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(21, 10000.0f, LoanIntentType::VENTURE, 1600.0f, 14.74f, LoanStatusType::YES));
    data.emplace_back(std::make_shared<Bank>(22, 85000.0f, LoanIntentType::VENTURE, 35000.0f, 10.37f, LoanStatusType::YES));
}

float AverageLoanAmount(BankContainer &data)
{
    if (data.empty())
    {
        std::runtime_error("No data available\n");
    }
    int total = 0;
    int count = 0;
    float result = 0.0f;
    for (auto &ptr : data)
    {
        if (ptr->loanIntent() == LoanIntentType::MEDICAL)
        {
            total += ptr->loanAmount();
            count++;
        }
    }
    result = float(total) / count;
    return result;
}

std::array<int, 4> ValueCount(BankContainer &data)
{
    std::array<int, 4> s;
    int education = 0, personal = 0, medical = 0, venture = 0;
    for (BankPointer &ptr : data)
    {
        if (ptr->loanIntent() == LoanIntentType::EDUCATION)
            education++;
        else if (ptr->loanIntent() == LoanIntentType::PERSONAL)
            personal++;
        else if (ptr->loanIntent() == LoanIntentType::MEDICAL)
            medical++;
        else
            venture++;
    }
    s[0] = education;
    s[1] = personal;
    s[2] = medical;
    s[3] = venture;
    return s;
}

float HighestInterestRateForAcceptedLoans(BankContainer &data)
{
    if (data.empty())
    {
        std::runtime_error("No data available\n");
    }
    std::vector<float> s;
    for (auto &ptr : data)
    {
        if (ptr->loanStatus() == LoanStatusType::YES)
        {
            s.push_back(ptr->loanIntRate());
        }
    }
    float max = *(std::max_element(s.begin(), s.end()));
    return max;
}

void MinMaxAge(BankContainer &data)
{
    if (data.empty())
    {
        std::runtime_error("No data available\n");
    }
    int min = 0;
    int max = 0;
    for (auto &ptr : data)
    {
        min = ptr->personAge();
        max = ptr->personAge();
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i]->personAge() > max)
                max = data[i]->personAge();
            if (data[i]->personAge() < min)
                min = data[i]->personAge();
        }
    }
    std::cout << "Max Age in dataset is: " << max << "\n";
    std::cout << "Min Age in dataset is: " << min << "\n";
}

std::vector<BankPointer> DetailsByCondition(BankContainer &data)
{
    std::vector<BankPointer> b(data.size());
    if (data.empty())
    {
        std::runtime_error("No data available\n");
    }
    // for (auto &ptr : data)
    // {
    //     if ((ptr->loanAmount() > 20000.0f && ptr->loanAmount() < 40000.0f) && (ptr->loanStatus() == LoanStatusType::YES) && (ptr->personAge() > 23))
    //         b.emplace_back(ptr);
    // }
    auto itr = std::copy_if(data.begin(), data.end(), b.begin(), [](const BankPointer &ptr)
                            { return ((ptr->loanAmount() > 20000.0f && ptr->loanAmount() < 40000.0f) && (ptr->loanStatus() == LoanStatusType::YES) &&
                                      (ptr->personAge() > 23)); });
    std::size_t newSize = std::distance(b.begin(), itr); // used to subtract two same objects
    b.resize(newSize);
    return b;
}
float MaxLoanIntRateByIntent(BankContainer &data, int l)
{
    LoanIntentType s;
    if (l == 0)
        s = LoanIntentType::PERSONAL;
    else if (l == 1)
        s = LoanIntentType::MEDICAL;
    else if (l == 2)
        s = LoanIntentType::VENTURE;
    else
        s = LoanIntentType::EDUCATION;
    if (data.empty())
    {
        std::runtime_error("No data available\n");
    }
    // float MaxInterest = 0.0f;
    // for (auto &ptr : data)
    // {
    //     if (ptr->loanIntent() == s)
    //     {
    //         if (ptr->loanIntRate() > MaxInterest)
    //             MaxInterest = ptr->loanIntRate();
    //     }
    // }
    auto max_loan_iter = std::max_element(data.begin(), data.end(), [s](const BankPointer &ptr1, const BankPointer &ptr2)
                                          { return ptr1->loanIntent() == s && ptr1->loanIntRate() < ptr2->loanIntRate(); });
    return (*max_loan_iter)->loanIntRate();
}

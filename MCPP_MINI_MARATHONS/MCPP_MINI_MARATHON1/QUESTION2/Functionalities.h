#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <array>
#include <vector>
#include "Bank.h"

using BankPointer = std::shared_ptr<Bank>;
using BankContainer = std::vector<BankPointer>;

void CreateObjects(BankContainer &data);
float AverageLoanAmount(BankContainer &data);
std::array<int, 4> ValueCount(BankContainer &data);
float HighestInterestRateForAcceptedLoans(BankContainer &data);
void MinMaxAge(BankContainer &data);
std::vector<BankPointer> DetailsByCondition(BankContainer &data);
float MaxLoanIntRateByIntent(BankContainer &data,int l);
#endif // FUNCTIONALITIES_H

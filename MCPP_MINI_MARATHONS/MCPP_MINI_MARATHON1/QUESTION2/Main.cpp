#include <array>
#include <iostream>
#include "Functionalities.h"

int main()
{
    BankContainer BankData;
    CreateObjects(BankData);

    std::cout << "AverageLoanAmount\n";
    std::cout << AverageLoanAmount(BankData) << "\n";

    std::array<int, 4> output = ValueCount(BankData);
    for (int i = 0; i < 4; i++)
    {
        std::cout << output[i] << "  ";
    }
    std::cout << std::endl;

    std::cout << "Highest HighestInterestRateForAcceptedLoans\n";
    std::cout << HighestInterestRateForAcceptedLoans(BankData) << "\n";

    std::cout << "MinMaxAge\n";
    MinMaxAge(BankData);

    std::cout << "DetailsByCondition\n";
    std::vector<BankPointer> bank = DetailsByCondition(BankData);
    for (auto &ptr : bank)
    {
        std::cout << *ptr << std::endl;
    }
    std::cout << std::endl;

    std::cout << "MaxLoanIntRateByIntent\n";
    std::cout << "0:Personal 1:Medical 2:Venture 3.Education\n";
    int l;
    std::cin >> l;
    std::cout << MaxLoanIntRateByIntent(BankData, l) << "\n";
}
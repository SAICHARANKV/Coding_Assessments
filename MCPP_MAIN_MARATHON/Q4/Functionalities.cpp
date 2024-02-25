#include "Functionalities.hpp"
#include <string>
#include <iostream>
#include <functional>
#include <optional>

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<Employee>(
        123456,
        "Sai",
        EmployeeType::FULL_TIME,
        22,
        1000,
        10));

    data.emplace_back(std::make_shared<BusinessOwner>(
        263736,
        "Chakri",
        BusinessType::SME,
        20,
        1420,
        7));

    data.emplace_back(std::make_shared<Employee>(
        135533,
        "KC",
        EmployeeType::PERMIT_HOLDER,
        21,
        2829,
        14));

    data.emplace_back(std::make_shared<BusinessOwner>(
        127333,
        "Bhupathi",
        BusinessType::INTERNATIONAL,
        45,
        3454,
        16));

    data.emplace_back(std::make_shared<Employee>(
        299237,
        "Abhi",
        EmployeeType::PERMIT_HOLDER,
        23,
        32213,
        15));
}

// First Functionality
void CountBussinessOwners(Container &data, int age)
{
    std::cout << "++++++++++++++++\n";

    if (data.empty())
        std::cout << "Empty Data!!!\n";
    int count = 0;
    for (auto &ele : data)
    {
        if (std::holds_alternative<BusinessPointer>(ele))
        {
            auto Bptr = std::get<BusinessPointer>(ele);
            if (Bptr->age() > age)
            {
                count++;
            }
        }
    }
    std::cout << "Count: " << count << "\n";
    std::cout << "++++++++++++++++\n";
}

// Second Functionality

void TaxableAmountAboveThreshold(Container &data, int amt)
{
    std::cout << "++++++++++++++++\n";
    if (data.empty())
        std::cout << "Empty Data!!!\n";
    bool ans = false;
    for (auto &ele : data)
    {
        if (std::holds_alternative<EmployeePointer>(ele))
        {
            auto Eptr = std::get<EmployeePointer>(ele);
            if (Eptr->taxableamount() > amt)
            {
                ans = true;
                break;
            }
        }
    }
    if (ans)
    {
        std::cout << "ALL EMPLOYESS ARE ABOVE THRESHOLD\n";
        std::cout << "++++++++++++++++\n";
    }

    else
    {
        std::cout << "SOME EMPLOYESS MIGHT BE ABOVE THRESHOLD\n";
        std::cout << "++++++++++++++++\n";
    }
}

// Third Functionality
void TaxPercentBelowThreshold(Container &data, std::future<int> &ft)
{
    if (data.empty())
    {
        std::cout << "Empty Data!!!\n";
        return;
    }
    int N = ft.get();
    std::vector<std::variant<EmployeePointer, BusinessPointer>> a;
    for (auto &ele : data)
    {
        if (std::holds_alternative<EmployeePointer>(ele))
        {
            auto Eptr = std::get<EmployeePointer>(ele);
            if (Eptr->taxPercent() < N)
            {
                a.emplace_back(Eptr);
                std::cout << "Employee ID: " << Eptr->regId() << ", Name: " << Eptr->name() << ", Tax Percent: " << Eptr->taxPercent() << "\n";
            }
        }
        else
        {
            auto Bptr = std::get<BusinessPointer>(ele);
            if (Bptr->taxPercent() < N)
            {
                a.emplace_back(Bptr);
                std::cout << "Business ID: " << Bptr->regId() << ", Name: " << Bptr->name() << ", Tax Percent: " << Bptr->taxPercent() << "\n";
            }
        }
    }
    std::cout << "Done!!!\n";
}

// Mapping Threads
void ThreadMapping(Container &data, ThreadArray &arr)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int n = 20;
    arr[0] = std::thread(std::bind(CountBussinessOwners, std::ref(data), 40));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    int amt = 1000;
    arr[1] = std::thread(TaxableAmountAboveThreshold, std::ref(data), std::ref(amt));
}

// Joining Threads
void JoinThreads(ThreadArray &arr)
{
    arr[0].join();
    arr[1].join();
}
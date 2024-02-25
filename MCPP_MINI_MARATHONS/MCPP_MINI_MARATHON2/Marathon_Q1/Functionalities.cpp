#include "Functionalities.h"
#include "EmptyContainerException.h"
#include <algorithm>
#include <iostream>

void CreateData(FnContainer &fns)
{

    Container TotalOddSumOf3 =
        [](std::vector<int> &data)
    {
        if (data.empty())
        {
            throw EmptyContainerException("Your data is empty");
        }
        int total = 0;
        for (auto &ptr : data)
        {
            if (ptr % 3 == 0 && ptr % 2 == 1)
            {
                total += ptr;
            }
        }
        return total;
    };

    Container LowestEvenNumer =
        [](std::vector<int> &data)
    {
        if (data.empty())
        {
            throw EmptyContainerException("Empty data");
        }
        auto &low = *std::min_element(data.begin(), data.end());
        return low;
    };

    Container MaxValue =
        [](std::vector<int> &data)
    {
        if (data.empty())
        {
            throw EmptyContainerException("Empty data");
        }
        auto &max = *std::max_element(data.begin(), data.begin() + 2);
        return max;
    };

    fns.push_back(TotalOddSumOf3);
    fns.push_back(LowestEvenNumer);
    fns.push_back(MaxValue);
}

void PerformOperation(FnContainer &fns, std::vector<int> &data)
{
    std::cout << "inside operaions" << std::endl;
    for (Container &fn : fns)
    {
        std::cout << "Value: " << fn(data) << std::endl;
    }
}

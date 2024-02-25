#include "Functionalities.h"
#include <iostream>

void MakeLambda(std::vector<std::function<void(std::array<int, 5>)>> &functions)
{

    std::function<void(std::array<int, 5>)> PrintSumOfFirstNIntegers =
        [](const std::array<int, 5> &data)
    {
        int n = data[4];
        float total = 0.0f;
        for (int i = 1; i <= n; i++)
        {
            total += i;
        }
        std::cout << "PrintSumOfFirstNIntegers"<<total
                  << "\n";
    };

    std::function<void(std::array<int, 5>)> DisplayEven =
        [](const std::array<int, 5> &data)
    {
        for (int ele : data)
        {
            if (ele % 2 == 0)
            {
                std::cout << "DisplayEven" << ele << "\n";
            }
        }
    };

    std::function<void(std::array<int, 5>)> SquareOfEach = [](const std::array<int, 5> &arr)
    {
        std::vector<int> vectorarr;
        for (int ele : arr)
        {
            std::cout << "Squareofeach" << ele * ele << "\n";
        }
    };

    std::function<void(std::array<int, 5>)> CubeOfEach = [](const std::array<int, 5> &arr)
    {
        for (int ele : arr)
        {
            std::cout << "CubeOfEach" << ele * ele * ele << "\n";
        }
    };
    functions.emplace_back(PrintSumOfFirstNIntegers);
    functions.emplace_back(DisplayEven);
    functions.emplace_back(SquareOfEach);
    functions.emplace_back(CubeOfEach);
}

std::array<int, 5> GenerateFiveIntegers(std::future<int> &input)
{
    int N= input.get();
    std::array<int, 5> result;
    int index = 0;
    for (int i = N; i < N + 5; i++)
    {
        result[index] = i;
        index++;
    }
    return result;
}

void JoinOfThreads(std::array<std::thread, 4> &arrThreads)
{
    for (std::thread &th : arrThreads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}

void MappingThreads(std::vector<std::function<void(std::array<int, 5>)>> &functions,
 std::array<std::thread, 4> &arrThreads, std::array<int, 5> &data)
{
    auto itr=functions.begin();
    for(std::thread& th:arrThreads)
    {
        th=std::thread(std::ref(*itr),data);
        itr++;
    }

}


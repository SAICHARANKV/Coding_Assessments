#include <thread>
#include <iostream>
#include <array>
#include <vector>
#include <future>
#include <functional>

// 1
void SumofFirstNPositiveNum()
{
    int N;
    int sum = 0; // Initialize sum
    std::cout << "Enter N:\n";
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        sum += i;
    }
    std::cout << "Sum is: " << sum << "\n";
}

// 2
void DisplayEvenNum(std::array<int, 5> data)
{
    if (data.empty())
    {
        std::cout << "No data!!!\n";
    }
    for (int ele : data)
    {
        if (ele % 2 == 0)
        {
            std::cout << "Display even num:  " << ele << "\n";
        }
    }
}

// 3
std::array<int, 5> Future5Integers(std::future<int> &ft)
{
    std::array<int, 5> arr;
    int Num = ft.get();
    int sum = 0; // Initialize sum
    for (int i = 0, j = Num; j < (Num + 5); j++, i++)
    {
        arr[i] = j;
    }
    std::cout << "Data Stored!!!\n";
    return arr;
}

// 4
void Squares(std::array<int, 5> data)
{
    std::vector<int> result;
    for (int ele : data)
    {
        result.push_back(ele * ele);
    }
    std::cout << "Squares Data Stored!!!\n";
}

// 5
void Cubes(std::array<int, 5> data)
{
    std::vector<int> result;
    for (int ele : data)
    {
        result.push_back(ele * ele * ele);
    }
    std::cout << "Cubes of Numbers: \n";
    for (int &ele : result)
    {
        std::cout << ele << "\n";
    }
}

// 6
void MapThreadsToAction(
    std::array<int, 5> data,
    std::array<std::thread, 3> &th)
{
    auto itr = data.begin();
    th[0] = std::thread(SumofFirstNPositiveNum);
    th[1] = std::thread(Squares, data);
    th[2] = std::thread(Cubes, data);

    std::cout << "Threads done!!!\n";
}

void joinThreads(std::array<std::thread, 3> &th)
{
    for (std::thread &t : th)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}

int main()
{
    // Data
    std::array<int, 5> data{1, 2, 3, 4, 5};
    std::array<std::thread, 3> arr;
    // ASYNCHRONOUS EXECUTION
    int N;
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::cin >> N;
    pr.set_value(N);
    std::future<std::array<int, 5>> result = std::async(std::launch::async, Future5Integers, std::ref(ft));
    std::array<int, 5> res = result.get();
    for (int itr = 0; itr < 5; itr++)
    {
        std::cout << res[itr] << "\t";
    }
    std::cout << "\n";
    std::future<void> res1 = std::async(std::launch::async, DisplayEvenNum, std::ref(data));
    res1.get();

    MapThreadsToAction(data, arr);
    joinThreads(arr);

    
}

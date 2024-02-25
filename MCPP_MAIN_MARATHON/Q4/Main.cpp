#include "Functionalities.hpp"
#include <iostream>
#include <thread>
int main()
{
    Container data;
    ThreadArray arr;
    std::cout << "++++++++++++++++\n";

    std::thread objthread(CreateObjects, std::ref(data));
    std::cout << "Data Stored!!!\n";
    objthread.join();

    // First 2 functionalities in threads
    try
    {
        ThreadMapping(data, arr);
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what() << "\n";
    }
    JoinThreads(arr);

    // Third functionality in async thread
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<void> a = std::async(std::launch::async, TaxPercentBelowThreshold, std::ref(data), std::ref(ft));
    std::cout << "++++++++++++++++\n";
    std::cout << "Enter Tax Percent Threshold\n";
    int N;
    std::cin >> N;
    pr.set_value(N);
    std::cout << "++++++++++++++++\n";
}
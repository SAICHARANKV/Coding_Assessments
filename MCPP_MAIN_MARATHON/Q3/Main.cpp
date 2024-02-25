#include <iostream>
#include <thread>
#include "ThreadHandler.hpp"
int main()
{
    ThreadHandler obj1(1, std::vector<int>{1, 2, 3, 4});
    std::thread t1(&ThreadHandler::inputCapture, &obj1);
    std::thread t2(&ThreadHandler::operation, &obj1);

    t1.join();
    t2.join();
}
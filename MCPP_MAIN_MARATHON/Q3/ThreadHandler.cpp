#include "ThreadHandler.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const ThreadHandler &rhs)
{
    os << " square_val: " << rhs.square_val
       << " square_val_avaliable: " << rhs.square_val_available;
    return os;
}

ThreadHandler::ThreadHandler(int val,std::vector<int> d)
    : square_val(val),data(d)
{
}

void ThreadHandler::operation()
{

    std::vector<int> data1;
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk, [&]()
            { return square_val_available; });
    std::cout << "Producer Function\n";
    for (int &ele : data)
    {

        ele = ele * ele;
        data1.push_back(ele);
        std::cout << "ele: " << ele << "\n";
    }
}

void ThreadHandler::inputCapture()
{
    std::vector<int> data;
    std::cout << "Consumer Function\n";
    square_val_available = true;
    cv.notify_one();
}

#ifndef THREADHANDLER_HPP
#define THREADHANDLER_HPP
#include <mutex>
#include <vector>
#include <condition_variable>
#include <ostream>
#include <thread>
class ThreadHandler
{
private:
    std::mutex mt;
    std::condition_variable cv;
    std::vector<int> data;
    int square_val{-1};
    bool square_val_available{false};
    int value{0};

public:
    /* Special Enablers and disablers */
    ThreadHandler() = delete;
    ThreadHandler(const ThreadHandler &) = delete;
    ThreadHandler(ThreadHandler &&) = delete;
    ThreadHandler &operator=(const ThreadHandler &) = delete;
    ThreadHandler &operator=(ThreadHandler &&) = delete;
    ~ThreadHandler() = default;

    /* Parameterized Constructor */
    ThreadHandler(int val,std::vector<int> d);
    /* Member Functions */
    void operation();
    void inputCapture();

    std::vector<int> getData() const { return data; }
    void setData(const std::vector<int> &data_) { data = data_; }

    friend std::ostream &operator<<(std::ostream &os, const ThreadHandler &rhs);
};
#endif // THREADHANDLER_HPP

#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingInstanceException.h"

#include <iostream>
#include <future>

int main()
{
    std::vector<std::variant<std::shared_ptr<ICECar>,
                             std::shared_ptr<EvCar>>>
        vectorVariant;
    std::future<void> functionality1 = std::async(std::launch::async, CreateObjects, std::ref(vectorVariant));
    functionality1.get();

    try
    {

        FuelType fuelTypeEnum = FuelType::PETROL;
        int N = 5;
        std::future<std::vector<std::shared_ptr<ICECar>>> functionality2 = std::async(std::launch::async, ReturnNSharedPointersWithEnum, std::ref(vectorVariant), std::ref(fuelTypeEnum), std::ref(N));
        std::vector<std::shared_ptr<ICECar>> r1 = functionality2.get();

        for (std::shared_ptr<ICECar> icecar : r1)
        {
            std::cout << *icecar;
        }
    }
    catch (EmptyContainerException e)
    {
        std::cout << e.what() << '\n';
    }
    catch (NoMatchingInstanceException e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "------------------------------------------------------------------";
    std::cout << "\n";

    try
    {
        std::future<bool> functionality3 = std::async(std::launch::async, ICECarAboveFuelCapacity30, std::ref(vectorVariant));
        bool r2 = functionality3.get();
        std::cout << "ICECarAboveFuelCapacity30" << r2 << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "------------------------------------------------------------------";
    std::cout << "\n";

    try
    {
        std::future<int> functionality4 = std::async(std::launch::async, CountEvCarInstances, std::ref(vectorVariant));
        int r3 = functionality4.get();
        std::cout << "CountEvCarInstances" << r3 << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "------------------------------------------------------------------";
    std::cout << "\n";

    try
    {
        int id1;
        std::cout << "Enter id:";
        std::cin >> id1;
        std::future<ChassisType> functionality5 = std::async(std::launch::async, ByChassisType, std::ref(vectorVariant), std::ref(id1));
        std::cout << "ByChassisType" << static_cast<int>(functionality5.get()) << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "------------------------------------------------------------------";
    std::cout << "\n";

    try
    {
        std::future<float> functionality6 = std::async(std::launch::async, TotalBatteryCapacity, std::ref(vectorVariant));
        float r4 = functionality6.get();
        std::cout << "ICECarAboveFuelCapacity30" << r4 << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (NoMatchingInstanceException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "------------------------------------------------------------------";
    std::cout << "\n";
    try
    {
        std::cout << "ReturnNInstance"
                  << "\n";
        int N1;
        std::cout << "Enter N1:";
        std::cin >> N1;
        std::future<std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>>> functionality7 = std::async(std::launch::async, ReturnNInstance, std::ref(vectorVariant), std::ref(N1));
        std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> r5 = functionality7.get();
        if (std::holds_alternative<std::shared_ptr<ICECar>>(r5))
        {
            std::cout << *std::get<0>(r5);
        }
        else
        {
            std::cout << *std::get<1>(r5);
        }
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
#include "Functionalities.h"
#include <iostream>
int main()
{
    VehicleContainer data;
    CreateObjects(data);

    std::list<TouristVehicle> s = NinstancesByCondition(data, 2);
    std::cout << "NinstancesByCondition\n";
    for (auto &ptr : s)
    {
        std::cout << ptr << std::endl;
    }
    std::cout << std::endl;
    std::cout << "FindMaxChargeTouristVehicle\n";
    FindMaxChargeTouristVehicle(data);
    std::cout << std::endl;
    std::cout
        << "AverageBookingCharge "
        << AverageBookingCharge(data, 1) << "\n";

    std::list<TouristVehicle> m = Ninstances(data, 3);
    for (auto &ptr : m)
    {
        std::cout << ptr << std::endl;
    }
    std::cout << std::endl;
}
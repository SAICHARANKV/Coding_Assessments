#include "Functionalities.hpp"
#include "Functionalities.cpp"
#include "Flight.hpp"
#include <iostream>

int main()
{
    FlightContainer FlightData;
    AirplaneContainer AirplaneData;
    std::cout << "------Creating Objects-------\n";
    AirplaneObjects(AirplaneData);
    FlightObjects(FlightData, AirplaneData);
    std::cout << "-------FindFlightOperatorType---------\n";
    std::vector<Airplane> result = FindFlightOperatorType(FlightData, FlightOperatorType::DOMESTIC);
    for (auto &ptr : result)
    {
        std::cout << ptr << "\n";
    }
    std::cout << "-----------FindAirplaneTypeBySeatCount------------\n";
    try
    {
        auto f1 = FindAirplaneTypeBySeatCount(FlightData);
        int n = static_cast<int>(f1);
        std::cout << "Airplane type with least seat count: " << static_cast<int>(f1) << "\n";
        if (n == 0)
            std::cout << "NEO\n";
        else if (n == 1)
            std::cout << "JUMBO\n";
        else
            std::cout << "CRUSELINER\n";
    }
    catch (NoInstanceFoundException &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "----------AirplanesOverThreshold--------\n";
    FlightContainer output = AirplanesOverThreshold(FlightData, 100);
    for (auto &ptr : output)
    {
        std::cout << *ptr << "\n";
    }
    std::cout << "------AirplaneSeatCount---------\n"
              << AirplaneSeatCount(FlightData) << "\n";
}
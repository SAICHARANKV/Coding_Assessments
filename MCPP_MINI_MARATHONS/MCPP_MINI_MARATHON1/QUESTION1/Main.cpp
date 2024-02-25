#include <iostream>
#include <algorithm>
#include "Functionalities.h"

int main()
{
    SensorContainer data; // Empty SensorContainer;
    std::cout << "Creating Objects!!!\n";
    CreateObjects(data);
    std::cout << "Find Instances Greater than 25 or not\n";
    try
    {
        if (ReadingAbove25(data))
        {
            std::cout << "Yes There are instances with reading above 25\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n--------------------\n";

    std::cout << "AverageReadingBySensorType\n";
    std::cout << AverageReadingBySensorType(data, SensorType::TEMPERATURE) << "\n";

    std::cout << "\n--------------------\n";
    try
    {
        std::cout << "Instances Satisfying Conditions\n";
        auto display = DisplaySensorInstancesByConditions(data);

        for (auto &display : DisplaySensorInstancesByConditions(data))
        {
            std::cout << display << std::endl;
        }
        //std::for_each(display.begin(), display.end(),)
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}
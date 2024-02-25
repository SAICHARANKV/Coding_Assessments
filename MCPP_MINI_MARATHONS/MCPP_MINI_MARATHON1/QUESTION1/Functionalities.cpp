
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Functionalities.h"

void CreateObjects(SensorContainer &data)
{
    int _id;
    std::string _name;
    int _type;
    SensorType _stype;
    int _reading;
    for (int i = 0; i < 3; i++)
    {
        std::cin >> _id;
        std::cin >> _name;
        std::cin >> _type;
        switch (_type)
        {
        case 0:
            _stype = SensorType::CABIN_PRESSURE;
            break;
        case 1:
            _stype = SensorType::TEMPERATURE;
            break;
        case 2:
            _stype = SensorType::TYRE_PRESSURE;
            break;
        }
        std::cin >> _reading;
        // Validate reading
        while (_reading < 0 || _reading > 20 || _reading % 10 != 0)
        {
            std::cout << "Re-enter correct reading: ";
            std::cin >> _reading;
        }

        data.emplace_back(std::make_shared<Sensor>(_id, _name, _stype, _reading));
    }
}

bool ReadingAbove25(SensorContainer &data)
{
    if (data.empty())
    {
        throw std::runtime_error("EMPTY CONTAINER");
    }

    // int count = 0;
    // for (SensorPointer &ptr : data)
    // {
    //     if (ptr->reading() > 25)
    //         count++;
    // }
    // STL
    int count = std::any_of(data.begin(), data.end(), [](const SensorPointer &ptr)
                            { return (ptr->reading() > 25); });

    if (count >= 1)
        return true;
    else
    {
        throw std::runtime_error("No Instances found with above 25 reading");
    }
}

float AverageReadingBySensorType(SensorContainer &data, SensorType stype)
{
    int count = 0;
    float result = 0.0f;
    // for (auto &ptr : data)
    // {
    //     if (stype == ptr->type())
    //     {
    //         count++;
    //         TotalReading = TotalReading + ptr->reading();
    //     }
    // }

    // STL
    float TotalReading = std::accumulate(data.begin(), data.end(), 0.0f, [&](float total, const SensorPointer &ptr)
                                         { return total + ptr->reading(); 
                                         count++; });

    if (count == 0)
    {
        throw std::runtime_error("Can't divide with ZERO!!");
    }
    result = TotalReading / count;
    return result;
}

std::list<Sensor> DisplaySensorInstancesByConditions(SensorContainer &data)
{
    if (data.empty())
    {
        throw std::runtime_error("EMPTY CONTAINER");
    }
    std::list<Sensor> p(data.size());
    // for (auto &detail : data)
    // {
    //     if (detail->reading() >= 15 && detail->type() == SensorType::TYRE_PRESSURE)
    //     {
    //         p.emplace_back(detail);
    //     }
    // }
    auto itr = std::copy_if(data.begin(), data.end(), p.begin(), [&](const SensorPointer &ptr)
                            { return (ptr->reading() >= 15 && ptr->type() == SensorType::TYRE_PRESSURE); });
    std::size_t newSize =
        std::distance(p.begin(), itr); // used to subtract two same objects
    p.resize(newSize);
    
    if (p.empty())
    {
        throw std::runtime_error("Your data is empty!!");
    }
    return p;
}

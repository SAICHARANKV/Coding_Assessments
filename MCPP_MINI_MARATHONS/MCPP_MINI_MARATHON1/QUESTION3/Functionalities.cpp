#include "Functionalities.h"
#include "Permit.h"
#include <iostream>
#include <algorithm>

void CreateObjects(VehicleContainer &data)
{
    data.emplace_back(std::make_shared<TouristVehicle>("S101", VehicleType::BUS, 30, 15,
                                                       std::make_shared<Permit>("S1011", PermitType::OWNED, 10)));
    data.emplace_back(std::make_shared<TouristVehicle>("S102", VehicleType::BUS, 40, 15,
                                                       std::make_shared<Permit>("S1022", PermitType::LEASE, 29)));
    data.emplace_back(std::make_shared<TouristVehicle>("S101", VehicleType::CAB, 5, 4,
                                                       std::make_shared<Permit>("S1033", PermitType::LEASE, 30)));
}

std::list<TouristVehicle> NinstancesByCondition(VehicleContainer &data, int n)
{
    if (data.empty())
    {
        std::runtime_error("No data\n");
    }
    std::list<TouristVehicle> ninstance(data.size());
    int count = 0;
    auto itr = std::copy_if(data.begin(), data.end(), ninstance.begin(), [&](const VehiclePointer &ptr)
                            { return ((ptr->seatCount() >= 4) &&
                                  (ptr->permit().get()->permitType() == PermitType::LEASE) && (count != n)); 
                                  count++; });
    size_t newSize=std::distance(ninstance.begin(),itr);
    ninstance.resize(newSize);
    

    // for (auto &ptr : data)
    // {
    //     if (ptr->seatCount() >= 4)
    //     {
    //         if (ptr->permit().get()->permitType() == PermitType::LEASE)
    //         {
    //             if (count != n)
    //             {
    //                 ninstance.emplace_back(*ptr);
    //                 count++;
    //             }
    //         }
    //     }
    // }
    return ninstance;
}

float AverageBookingCharge(VehicleContainer &data, int type)
{
    VehicleType s;
    if (type == 0)
        s = VehicleType::CAB;
    else if (type == 1)
        s = VehicleType::BUS;
    else
        s = VehicleType::BIKE;

    if (data.empty())
    {
        std::runtime_error("No data available\n");
    }
    int total = 0, count = 0;
    float result = 0.0f;
    for (auto &ptr : data)
    {
        if (ptr->type() == s)
        {
            total += ptr->perHourBookingCharge();
            count++;
        }
    }
    result = float(total) / count;
    return result;
}

void FindMaxChargeTouristVehicle(VehicleContainer &data)
{
    if (data.empty())
    {
        std::runtime_error("No data\n");
    }
    int max = 0;
    for (auto &ptr : data)
    {
        max = ptr->perHourBookingCharge();
        for (int i = 0; i < data.size(); i++)
        {
            if (max < ptr->perHourBookingCharge())
                max = ptr->perHourBookingCharge();
        }
    }

    for (auto &ptr : data)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (ptr->perHourBookingCharge() == max)
            {
                std::cout << *ptr << std::endl;
            }
        }
    }
}

std::list<TouristVehicle> Ninstances(VehicleContainer &data, int n)
{
    if (data.empty())
    {
        std::runtime_error("No data\n");
    }
    std::list<TouristVehicle> ninstance;
    int count = 0;
    for (auto &ptr : data)
    {
        if (count != n)
        {
            ninstance.emplace_back(*ptr);
            count++;
        }
    }

    return ninstance;
}

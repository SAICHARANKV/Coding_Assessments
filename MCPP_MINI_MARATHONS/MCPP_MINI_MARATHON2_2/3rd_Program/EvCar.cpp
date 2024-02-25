#include "EvCar.h"
#include<iostream>

EvCar::EvCar(int id,
 ChassisType chassisType, float batteryCapacity)
 :_id(id),_chassisType(chassisType),_batteryCapacity(batteryCapacity)
{
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_id: " << rhs._id<<"\n"
       << " _batteryCapacity: " << rhs._batteryCapacity;
       if(rhs._chassisType==ChassisType::LADDER)
       {
        std::cout<<"ChassisType::LADDER"<<"\n";
       }
       else if(rhs._chassisType==ChassisType::LADDER)
       {
        std::cout<<"ChassisType::LADDER"<<"\n";
       }
    return os;
}



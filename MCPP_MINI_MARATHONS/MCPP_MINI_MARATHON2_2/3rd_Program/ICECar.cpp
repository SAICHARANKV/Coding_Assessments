#include "ICECar.h"
#include<iostream>

ICECar::ICECar(int id, 
FuelType fuelType, int fuelTankCapacity)
:_id(id),_fuelType(fuelType),_fuelTankCapacity(fuelTankCapacity)
{
}
std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    os << "_id: " << rhs._id<<"\n"
       << " _fuelTankCapacity: " << rhs._fuelTankCapacity<<"\n";
       if(rhs._fuelType==FuelType::PETROL)
       {
        std::cout<<"FuelType::PETROL"<<"\n";
       }
       else if(rhs._fuelType==FuelType::DIESEL)
       {
        std::cout<<"FuelType::DIESEL"<<"\n";
       }

    return os;
}

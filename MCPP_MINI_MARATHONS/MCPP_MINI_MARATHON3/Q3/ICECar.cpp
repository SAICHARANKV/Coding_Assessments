#include "ICECar.hpp"

ICECar::ICECar(int id, FuelType fuelType, unsigned int capacity)
    : _id(id), _fuelType(fuelType), _fuelTankCapacity(capacity)
{
}
std::ostream &operator<<(std::ostream &os, const ICECar &rhs)
{
    os << "_id: " << rhs._id
       << " _fuelType: " << static_cast<int>(rhs._fuelType)
       << " _fuelTankCapacity: " << rhs._fuelTankCapacity;
    return os;
}

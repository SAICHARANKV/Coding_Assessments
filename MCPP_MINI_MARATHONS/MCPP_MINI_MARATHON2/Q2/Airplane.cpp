#include "Airplane.hpp"
Airplane::Airplane(std::string airplaneManufacturer, AirplaneType atype, int seats)
    : _airplaneManufacturer(airplaneManufacturer), _airplaneType(atype), _airplaneSeatCount(seats)
{
}
std::ostream &operator<<(std::ostream &os, const Airplane &rhs)
{
    os << "\nAirplaneManufacturer: " << rhs._airplaneManufacturer
       << "\nAirplaneType: " << static_cast<int>(rhs._airplaneType)
       << "\nAirplaneSeatCount: " << rhs._airplaneSeatCount << "\n";
    return os;
}

#include "TouristVehicle.h"

TouristVehicle::TouristVehicle(std::string number, VehicleType vtype, int seats, float charge, PermitPointer permit)
    : _number(number), _type(vtype), _seat_count(seats), _per_hour_booking_charge(charge), _permit(permit)
{
}

TouristVehicle::TouristVehicle(std::string number, VehicleType vtype, int seats, float charge)
    : _number(number), _type(vtype), _seat_count(seats), _per_hour_booking_charge(charge)

{
}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs)
{
    os << "_number: " << rhs._number
       << " _type: " << static_cast<int>(rhs._type)
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " _permit: " << rhs._permit.get() << "\n";
    return os;
}

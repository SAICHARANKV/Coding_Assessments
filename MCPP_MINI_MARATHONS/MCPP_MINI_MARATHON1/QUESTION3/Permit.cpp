#include "Permit.h"

Permit::Permit(std::string serialnumber, PermitType ptype, int durationleft)
    : _serial_number(serialnumber), _permit_type(ptype), _permit_duration_left(durationleft)
{
}
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serial_number: " << rhs._serial_number
       << " _permit_type: " << static_cast<int>(rhs._permit_type)
       << " _permit_duration_left: " << rhs._permit_duration_left;
    return os;
}

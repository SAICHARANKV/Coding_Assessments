#include "Plane.h"

std::ostream &operator<<(std::ostream &os, const Plane &rhs) {
    os << "_planeId: " << rhs._planeId
       << " _planeType:" ;
    switch(rhs._planeType)
    {
        case PlaneType::NEO:os<<"NEO";
        break;
        case PlaneType::JUMBO:os<<"JUMBO";
        break;
        case PlaneType::LUXURY:os<<"LUXURY";
        break;
    }
    os<< " _capacity: " << rhs._capacity;
    return os;
}

Plane::Plane(std::string id, PlaneType type, int capacity)
:_planeId(id),_planeType(type),_capacity(capacity)
{
}
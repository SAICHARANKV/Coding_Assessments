#include"Flight.h"

std::ostream &operator<<(std::ostream &os, const Flight &rhs) {
    os << "_duration_minutes: " << rhs._duration_minutes
       << " _ticket_price: " << rhs._ticket_price
       << " _plane: " << *(rhs._plane.get());
    return os;
}

Flight::Flight(int duration, float price, RefSharedType plane)
:_duration_minutes(duration),_ticket_price(price),_plane(plane)
{
}
#include "Flight.hpp"

Flight::Flight(std::string company, FlightOperatorType ftype, AirplaneRef flightAssociatedPlane)
    : _flightOperatorCompany(company), _flightOperatorType(ftype), _flightAssociatedPlane(flightAssociatedPlane)
{
}

std::ostream &operator<<(std::ostream &os, const Flight &rhs)
{
    os << "\nFlightOperatorCompany: " << rhs._flightOperatorCompany
       << "\nFlightOperatorType: " << static_cast<int>(rhs._flightOperatorType)
       << "\nFlightAssociatedPlane: " << rhs._flightAssociatedPlane.get();
    return os;
}

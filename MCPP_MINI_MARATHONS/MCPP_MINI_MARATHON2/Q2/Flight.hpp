#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>
#include <iostream>
#include <functional>
#include "FlightOperatorType.hpp"
#include "Airplane.hpp"

using AirplaneRef = std::reference_wrapper<Airplane>;
class Flight
{
private:
    std::string _flightOperatorCompany{""};
    FlightOperatorType _flightOperatorType{FlightOperatorType::DOMESTIC};
    AirplaneRef _flightAssociatedPlane;

public:
    Flight() = default;
    ~Flight() = default;
    Flight(const Flight &) = default;
    Flight(Flight &&) = default;
    Flight &operator=(const Flight &) = default;
    Flight &operator=(Flight &&) = default;

    Flight(std::string company, FlightOperatorType ftype, AirplaneRef flightAssociatedPlane);

    std::string flightOperatorCompany() const { return _flightOperatorCompany; }
    void setFlightOperatorCompany(const std::string &flightOperatorCompany) { _flightOperatorCompany = flightOperatorCompany; }

    FlightOperatorType flightOperatorType() const { return _flightOperatorType; }
    void setFlightOperatorType(const FlightOperatorType &flightOperatorType) { _flightOperatorType = flightOperatorType; }

    AirplaneRef flightAssociatedPlane() const { return _flightAssociatedPlane; }

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);

};

#endif // FLIGHT_HPP

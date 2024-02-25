#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include <memory>
#include <vector>
#include "Flight.hpp"

using FlightPointer = std::shared_ptr<Flight>;
using FlightContainer = std::vector<FlightPointer>;
using AirplaneContainer = std::vector<Airplane>;

#endif // FUNCTIONALITIES_HPP

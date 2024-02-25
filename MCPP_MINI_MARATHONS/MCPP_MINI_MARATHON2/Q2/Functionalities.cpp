#include "Functionalities.hpp"
#include "NoInstanceFoundException.hpp"
#include "EmptyContainerException.hpp"

auto AirplaneObjects = [](AirplaneContainer &AirplaneData)
{
    AirplaneData.emplace_back("Tata", AirplaneType::NEO, 220);
    AirplaneData.emplace_back("Mahindra", AirplaneType::JUMBO, 150);
    AirplaneData.emplace_back("JetAirs", AirplaneType::NEO, 230);
};
auto FlightObjects = [](FlightContainer &FlightData, AirplaneContainer &AirplaneData)
{
    FlightData.emplace_back(std::make_shared<Flight>("Emirates", FlightOperatorType::INTERNATIONAL, AirplaneData[0]));
    FlightData.emplace_back(std::make_shared<Flight>("AirIndia", FlightOperatorType::DOMESTIC, AirplaneData[1]));
    FlightData.emplace_back(std::make_shared<Flight>("Indigo", FlightOperatorType::DOMESTIC, AirplaneData[2]));
};
// Functionalities
auto FindFlightOperatorType = [](FlightContainer &FlightData, FlightOperatorType ftype) -> AirplaneContainer
{
    AirplaneContainer p;

    for (auto &ptr : FlightData)
    {
        if (ptr.get()->flightOperatorType() == ftype)
        {
            p.emplace_back(ptr.get()->flightAssociatedPlane().get());
        }
    }
    return p;
};

auto FindAirplaneTypeBySeatCount = [](FlightContainer &FlightData) -> AirplaneType
{
    if (FlightData.empty())
        throw EmptyContainerException("No Data found");

    int minSeatCount = FlightData[0]->flightAssociatedPlane().get().airplaneSeatCount();
    for (const auto &ptr : FlightData)
    {
        int seatCount = ptr->flightAssociatedPlane().get().airplaneSeatCount();
        if (seatCount < minSeatCount)
            minSeatCount = seatCount;
    }

    for (const auto &ptr : FlightData)
    {
        if (ptr->flightAssociatedPlane().get().airplaneSeatCount() == minSeatCount)
        {
            return ptr->flightAssociatedPlane().get().airplaneType();
        }
    }

    throw NoInstanceFoundException("No instance found with the minimum seat count");
};

auto AirplanesOverThreshold = [](FlightContainer &FlightData, int seatcount) -> FlightContainer
{
    FlightContainer p;
    for (auto &ptr : FlightData)
    {
        if (ptr->flightAssociatedPlane().get().airplaneSeatCount() > seatcount)
        {
            p.emplace_back(ptr);
        }
    }

    return p;
};
auto AirplaneSeatCount = [](FlightContainer &FlightData) -> int
{
    int total = 0;
    for (auto &ptr : FlightData)
    {
        total = total + ptr->flightAssociatedPlane().get().airplaneSeatCount();
    }
    return total;
};

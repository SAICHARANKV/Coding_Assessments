#include <string>
#include <ostream>
#include "AirplaneType.hpp"

class Airplane
{
private:
    std::string _airplaneManufacturer;
    AirplaneType _airplaneType;
    int _airplaneSeatCount;

public:
    Airplane() = default;
    ~Airplane() = default;
    Airplane(const Airplane &) = default;
    Airplane(Airplane &&) = default;
    Airplane &operator=(const Airplane &) = default;
    Airplane &operator=(Airplane &&) = default;

    Airplane(std::string airplaneManufacturer, AirplaneType atype, int seats);

    std::string airplaneManufacturer() const { return _airplaneManufacturer; }
    void setAirplaneManufacturer(const std::string &airplaneManufacturer) { _airplaneManufacturer = airplaneManufacturer; }

    AirplaneType airplaneType() const { return _airplaneType; }
    void setAirplaneType(const AirplaneType &airplaneType) { _airplaneType = airplaneType; }

    int airplaneSeatCount() const { return _airplaneSeatCount; }
    void setAirplaneSeatCount(int airplaneSeatCount) { _airplaneSeatCount = airplaneSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Airplane &rhs);

};
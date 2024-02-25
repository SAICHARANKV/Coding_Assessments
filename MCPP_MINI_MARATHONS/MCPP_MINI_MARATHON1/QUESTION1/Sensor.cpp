#include "Sensor.h"

// // Deligated Instantination
// Sensor::Sensor(int id)
//     : _id(id) {}

// Sensor::Sensor(int id, std::string name)
//     : Sensor(id)
// {
//     _name = name;
// }

// Sensor::Sensor(int id, std::string name, SensorType type)
//     : Sensor(id, name)
// {
//     _type = type;
// }

Sensor::Sensor(int id, std::string name, SensorType type, int reading)
    : _id(id),  _name(name), _type(type), _reading(reading)
{
}

std::ostream &operator<<(std::ostream &os, const Sensor &rhs)
{
    os << "_id: " << rhs._id << "\n"
       << " _name: " << rhs._name << "\n";
    //    << " _type: " << static_cast<int>(rhs._type);
    // if (rhs._type == SensorType::TYRE_PRESSURE)
    //     os << "TYRE_PRESSURE";
    // else if (rhs._type == SensorType::TEMPERATURE)
    //     os << "TEMPERATURE";
    // else if (rhs._type == SensorType::CABIN_PRESSURE)
    //     os << "CABIN_PRESSURE";

    os << " Reading: " << rhs._reading;
    return os;
}

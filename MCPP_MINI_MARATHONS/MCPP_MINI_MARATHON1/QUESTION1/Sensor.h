#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <iostream>
#include "SensorType.h"
class Sensor
{
private:
    int _id{0};
    std::string _name{""};
    SensorType _type{SensorType::TYRE_PRESSURE};
    int _reading{0};

public:
    /*
    Special Enablers and disablers
    */
    Sensor() = delete;
    Sensor(const Sensor &) = delete;
    Sensor &operator=(const Sensor &) = delete;
    Sensor(Sensor &&) = delete; // Move constructor
    Sensor &operator=(Sensor &&) = delete;
    ~Sensor() = default;

    /*
    User Defined Parameterized constructors
    */
    // explicit Sensor(int id);
    // Sensor(int id, std::string name);
    // Sensor(int id, std::string name, SensorType type);
    Sensor(int id, std::string name, SensorType type, int reading);

    /*
    Getters and Setters
    */
    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    SensorType type() const { return _type; }
    void setType(const SensorType &type) { _type = type; }

    int reading() const { return _reading; }
    void setReading(int reading) { _reading = reading; }

    friend std::ostream &operator<<(std::ostream &os, const Sensor &rhs);
};

#endif // SENSOR_H

#ifndef EvCar_HPP
#define EvCar_HPP
#include "ChassisType.hpp"

class EvCar
{
private:
    int _id;
    ChassisType _chassisType;
    float _batteryCapacity;

public:
    /* Special Enablers and disablers */
    EvCar() = delete;
    EvCar(const EvCar &) = delete;
    EvCar(EvCar &&) = delete;
    EvCar &operator=(const EvCar &) = delete;
    EvCar &operator=(EvCar &&) = delete;
    ~EvCar() = default;

    /* Parameterized Constructor */
    EvCar(int id, ChassisType ctype, float bcapacity);

    /* Getter and Setters */
    int id() const { return _id; }
    void setId(int id) { _id = id; }

    ChassisType chassisType() const { return _chassisType; }
    void setChassisType(const ChassisType &chassisType) { _chassisType = chassisType; }

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }
};

#endif // EvCar_HPP

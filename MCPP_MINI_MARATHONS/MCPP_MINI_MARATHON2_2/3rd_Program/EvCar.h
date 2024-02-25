#ifndef EVCAR_H
#define EVCAR_H

#include"ChassisType.h"
#include <ostream>

class EvCar
{
    int _id;
    ChassisType _chassisType;
    float _batteryCapacity;

    public:
        EvCar()=delete;
        EvCar(const EvCar&)=default;
        EvCar(EvCar&&)=delete;
        EvCar& operator=(const EvCar&)=delete;
        EvCar& operator=(EvCar&&)=delete;
        ~EvCar()=default;

        EvCar(int id,ChassisType chassisType,float batteryCapacity);

        int id() const { return _id; }
        void setId(int id) { _id = id; }

        ChassisType chassisType() const { return _chassisType; }
        void setChassisType(const ChassisType &chassisType) { _chassisType = chassisType; }

        float batteryCapacity() const { return _batteryCapacity; }
        void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

        friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);



};

#endif // EVCAR_H

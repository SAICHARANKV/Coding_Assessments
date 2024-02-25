#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include<string>
#include"BatteryType.h"
#include"Motor.h"
#include<functional>
#include <ostream>

using RefType=std::reference_wrapper<Motor>;

class ElectricVehicle
{
private:
    const std::string _vehicleId;
    const std::string _vehicleModel;
    BatteryType _batteryType;
    float _batteryCapacity;
    RefType _motor;

public:
//special member functions
   ElectricVehicle()=delete;
   ElectricVehicle(const ElectricVehicle&)=delete;
   ElectricVehicle& operator=(const ElectricVehicle&)=delete;
   ElectricVehicle(ElectricVehicle&&)=delete;
   ElectricVehicle& operator=(ElectricVehicle&&)=delete;
   ~ElectricVehicle()=default;

//getters and setters
   std::string vehicleId() const { return _vehicleId; }
   std::string vehicleModel() const { return _vehicleModel; }
   BatteryType batteryType() const { return _batteryType; }
   void setBatteryType(const BatteryType &batteryType) { _batteryType = batteryType; }
   float batteryCapacity() const { return _batteryCapacity; }
   void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }
   RefType motor() const { return _motor; }
   void setMotor(const RefType &motor) { _motor = motor; }

//parameterized constructor
   ElectricVehicle(std::string vehicleId,std::string vehicleModel,BatteryType batteryType,float batteryCapacity,RefType motor);

//member functions
   float EvaluateChargingRate();
   float operator+(const ElectricVehicle& e);
   friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);

};

#endif // ELECTRICVEHICLE_H
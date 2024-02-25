#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(std::string vehicleId, std::string vehicleModel, BatteryType batteryType, float batteryCapacity, RefType motor)
:_vehicleId(vehicleId),_vehicleModel(vehicleModel),_batteryType(batteryType),_batteryCapacity(batteryCapacity),_motor(motor)
{
}

std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_vehicleId: " << rhs._vehicleId
       << " _vehicleModel: " << rhs._vehicleModel
       << " _batteryType: " ;
       switch(rhs._batteryType)
       {
            case BatteryType::LITHIUM_ION:os<<"LITHIUM_ION";
            break;
            case BatteryType::NICKEL_METAL_HYDRIDE:os<<"NICKEL_METAL_HYDRIDE";
            break;
       }
       os<< "  _batteryCapacity: " << rhs._batteryCapacity
       << " _motor: " << rhs._motor.get()<<"\n";
    return os;
}

float ElectricVehicle::EvaluateChargingRate()
{
    if(_batteryCapacity<=40)
        return 30;
    else
        return 40;
}

float ElectricVehicle::operator+(const ElectricVehicle &e)
{
    return motor().get().maxPower()+e.motor().get().maxPower();
}
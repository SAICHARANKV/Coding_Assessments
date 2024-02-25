#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<memory>
#include"ElectricVehicle.h"
#include"Motor.h"
#include<vector>
#include"EmptyContainerException.h"
#include<functional>


using VehiclePointer=std::shared_ptr<ElectricVehicle>;
using VehicleConatiner=std::vector<VehiclePointer>;
using MotorContainer=std::vector<Motor>;

void CreateObjects(VehicleConatiner& vehicleData,MotorContainer& motorData);
int FindMaxTorqueById(VehicleConatiner& vehicleData,std::string id);
float CalculateBatteryDrainPercentageByBatteryType(VehicleConatiner& vehicleData);
VehicleConatiner FilterData(VehicleConatiner& vehicleData,std::function<bool(int)> fn);
float FindMaxPowerOf2Instances(VehiclePointer& data1,VehiclePointer& data2);




#endif // FUNCTIONALITIES_H
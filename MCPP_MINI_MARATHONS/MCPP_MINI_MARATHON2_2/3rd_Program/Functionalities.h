#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"ICECar.h"
#include"EvCar.h"
#include<vector>
#include<variant>
#include<memory>

void CreateObjects
(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant);

std::vector<std::shared_ptr<ICECar>> ReturnNSharedPointersWithEnum
(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant,
FuelType fueltype,int n);

bool ICECarAboveFuelCapacity30(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant);

int CountEvCarInstances(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant);

ChassisType ByChassisType(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant,int id);

float TotalBatteryCapacity(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant);

std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> ReturnNInstance(std::vector<std::variant<std::shared_ptr<ICECar>,std::shared_ptr<EvCar>>>& vectorVariant,int N);


#endif // FUNCTIONALITIES_H

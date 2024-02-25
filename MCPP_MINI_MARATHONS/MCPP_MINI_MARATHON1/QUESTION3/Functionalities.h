#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <memory>
#include <list>
#include "TouristVehicle.h"
using VehiclePointer = std::shared_ptr<TouristVehicle>;
using VehicleContainer = std::list<VehiclePointer>;

void CreateObjects(VehicleContainer &data);
std::list<TouristVehicle> NinstancesByCondition(VehicleContainer &data, int n);
float AverageBookingCharge( VehicleContainer &data,int type);
void FindMaxChargeTouristVehicle(VehicleContainer &data);
std::list<TouristVehicle> Ninstances(VehicleContainer &data, int n);

#endif // FUNCTIONALITIES_H

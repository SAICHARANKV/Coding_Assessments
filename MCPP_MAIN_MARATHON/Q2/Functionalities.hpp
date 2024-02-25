#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include <memory>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include "Vehicle.hpp"
#include "ServiceRecord.hpp"
#include "EmptyContainerException.hpp"

using VehiclePointers = std::shared_ptr<Vehicle>;
using VehicleContainer = std::vector<VehiclePointers>;
using MapContainer = std::unordered_map<std::string, VehiclePointers>;

void CreateObjects(VehicleContainer &vdata, MapContainer &data);
void LastNInstances(MapContainer &data, int n);
std::vector<std::pair<std::string, std::string>> ReturnListInstances(std::list<std::string> &ids, MapContainer &data);
std::pair<std::string, ServicePointers> MaxServiceChargeInList(MapContainer &data);
float ReturnRegularAverageServiceCharge(MapContainer &data);
std::string VehicleIdByServiceId(MapContainer &data,std::string sid);
#endif // FUNCTIONALITIES_HPP

#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include <array>
#include <memory>
#include <functional>
#include "Automobile.hpp"
#include <algorithm>
#include <numeric>
#include <vector>
#include "EmptyContainerException.hpp"
#include "NoInstanceFoundException.hpp"

using AutomobilePointers = std::shared_ptr<Automobile>;
using Container = std::array<AutomobilePointers, 3>;

void CreateObjects(Container &data);
std::optional<float> DisplayGreenPassCostById(Container &data, std::string id);
float AveragePrice(Container &data);
std::vector<PrivilegeCategory> FindPrivilegeType(Container &data);

#endif // FUNCTIONALITIES_HPP

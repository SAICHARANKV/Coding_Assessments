#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <memory>
#include <vector>
#include <variant>
#include "ICECar.hpp"
#include "EvCar.hpp"

using IcePointer = std::shared_ptr<ICECar>;
using EvCarPointer = std::shared_ptr<EvCar>;
using Container = std::vector<std::variant<IcePointer, EvCarPointer>>;

void CreateObjects(Container &data);

#endif // FUNCTIONALITIES_HPP

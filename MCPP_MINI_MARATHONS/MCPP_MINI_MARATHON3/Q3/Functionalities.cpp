#include "Functionalities.hpp"

void CreateObjects(Container &data)
{
    data.emplace_back(std::make_shared<EvCar>(1, ChassisType::TUBULAR, 19.0f));
    data.emplace_back(std::make_shared<EvCar>(2, ChassisType::LADDER, 21.3f));
    data.emplace_back(std::make_shared<EvCar>(3, ChassisType::TUBULAR, 23.9f));
    data.emplace_back(std::make_shared<ICECar>(4, FuelType::PETROL, 44));
    data.emplace_back(std::make_shared<ICECar>(5, FuelType::DIESEL, 34));
    data.emplace_back(std::make_shared<ICECar>(6, FuelType::DIESEL, 55));
}
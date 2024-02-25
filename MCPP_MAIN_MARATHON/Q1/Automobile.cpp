#include "Automobile.hpp"

Automobile::Automobile(std::string id, std::string brand, AutomobileType category, float price, std::string model)
    : _id(id), _brand(brand), _category(category), _price(price), _model(model)
{
}

std::ostream &operator<<(std::ostream &os, const Automobile &rhs)
{
    os << "_id: " << rhs._id
       << " _brand: " << rhs._brand
       << " _category: " << static_cast<int>(rhs._category)
       << " _price: " << rhs._price
       << " _model: " << rhs._model;
    return os;
}

PrivilegeCategory Automobile::FindPrivilegeType()
{
    if (_category == AutomobileType::PRIVATE && _price > 250000.0f)
        return PrivilegeCategory::VIP;
    else if (_category == AutomobileType::DEFENSE)
        return PrivilegeCategory::GOVT;
    return PrivilegeCategory::PERSONAL;
}

float Automobile::GreenPassCost()
{
    if (_category == (AutomobileType::PRIVATE) || (_category == (AutomobileType::TRANSPORT)))
        return _price * 0.1f;
    return 0.0f;
}

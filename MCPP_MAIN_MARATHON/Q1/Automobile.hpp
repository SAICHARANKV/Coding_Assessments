#ifndef AUTOMOBILE_HPP
#define AUTOMOBILE_HPP
#include <string>
#include <ostream>
#include "AutomobileType.hpp"
#include "PrivilegeCategory.hpp"
class Automobile
{
private:
    std::string _id{""};
    std::string _brand{""};
    AutomobileType _category{AutomobileType::DEFENSE};
    float _price{0.0f};
    std::string _model{""};

public:
    /* Special Enablers and disablers */
    Automobile() = delete;
    Automobile(const Automobile &) = delete;
    Automobile(Automobile &&) = delete;
    Automobile &operator=(const Automobile &) = delete;
    Automobile &operator=(Automobile &&) = delete;
    ~Automobile() = default;

    /* Parameterized Constructor */
    Automobile(std::string id, std::string brand, AutomobileType category, float price, std::string model);

    /* Getter and Setters */
    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string brand() const { return _brand; }
    void setBrand(const std::string &brand) { _brand = brand; }

    AutomobileType category() const { return _category; }
    void setCategory(const AutomobileType &category) { _category = category; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    /* Member Functions */
    PrivilegeCategory FindPrivilegeType();
    float GreenPassCost();

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
};

#endif // AUTOMOBILE_HPP

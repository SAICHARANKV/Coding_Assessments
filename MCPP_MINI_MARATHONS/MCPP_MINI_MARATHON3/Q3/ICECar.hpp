#ifndef ICECAR_HPP
#define ICECAR_HPP
#include "FuelType.hpp"
#include <ostream>
class ICECar
{
private:
    int _id;
    FuelType _fuelType;
    unsigned int _fuelTankCapacity;

public:
    /* Special Enablers and disablers */
    ICECar() = delete;
    ICECar(const ICECar &) = delete;
    ICECar(ICECar &&) = delete;
    ICECar &operator=(const ICECar &) = delete;
    ICECar &operator=(ICECar &&) = delete;
    ~ICECar() = default;

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    FuelType fuelType() const { return _fuelType; }
    void setFuelType(const FuelType &fuelType) { _fuelType = fuelType; }

    unsigned int fuelTankCapacity() const { return _fuelTankCapacity; }
    void setFuelTankCapacity(unsigned int fuelTankCapacity) { _fuelTankCapacity = fuelTankCapacity; }

    /* Parameterized Constructor */
    ICECar(int id,FuelType fuelType,unsigned int capacity);

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);

    /* Getter and Setters */
    
};

#endif // ICECAR_HPP

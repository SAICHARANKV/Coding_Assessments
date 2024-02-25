#ifndef ICECAR_H
#define ICECAR_H

#include"FuelType.h"
#include <ostream>
class ICECar
{
    int _id;
    FuelType _fuelType;
    int _fuelTankCapacity;

    public:
        ICECar()=delete;
        ICECar(const ICECar&)=default;
        ICECar(ICECar&&)=delete;
        ICECar& operator=(const ICECar&)=delete;
        ICECar& operator=(ICECar&&)=delete;
        ~ICECar()=default;

        ICECar(int id,FuelType fuelType,int fuelTankCapacity);

        int id() const { return _id; }
        void setId(int id) { _id = id; }

        FuelType fuelType() const { return _fuelType; }
        void setFuelType(const FuelType &fuelType) { _fuelType = fuelType; }

        int fuelTankCapacity() const { return _fuelTankCapacity; }
        void setFuelTankCapacity(int fuelTankCapacity) { _fuelTankCapacity = fuelTankCapacity; }

        friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);

        


};

#endif // ICECAR_H

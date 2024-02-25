#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingInstanceException.h"

void CreateObjects(std::vector<std::variant<std::shared_ptr<ICECar>,
                                            std::shared_ptr<EvCar>>> &vectorVariant)
{
    vectorVariant.push_back(
        std::make_shared<EvCar>(10, ChassisType::LADDER, 25.0f));

    vectorVariant.push_back(
        std::make_shared<EvCar>(11, ChassisType::TUBULAR, 26.0f));

    vectorVariant.push_back(
        std::make_shared<ICECar>(20, FuelType::PETROL, 35));

    vectorVariant.push_back(
        std::make_shared<ICECar>(21, FuelType::DIESEL, 36));
}

std::vector<std::shared_ptr<ICECar>>
ReturnNSharedPointersWithEnum(std::vector<std::variant<std::shared_ptr<ICECar>,
                                                       std::shared_ptr<EvCar>>> &vectorVariant,
                              FuelType fueltype, int n)
{
    if (vectorVariant.empty())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }
    std::vector<std::shared_ptr<ICECar>> result;
    for (std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> &variants : vectorVariant)
    {
        if (std::holds_alternative<std::shared_ptr<ICECar>>(variants))
        {
            std::shared_ptr<ICECar> h = std::get<0>(variants);
            if (h->fuelType() == fueltype)
            {
                result.emplace_back(h);
            }
        }
    }
    std::vector<std::shared_ptr<ICECar>> result1;
    if (result.size() > n)
    {
        for (int i = 0; i < n; i++)
        {
            result1.emplace_back(result[i]);
        }
    }
    if (result1.empty())
    {
        throw NoMatchingInstanceException("NoMatchingInstance\n");
    }
    return result1;
}

bool ICECarAboveFuelCapacity30(std::vector<std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>>> &vectorVariant)
{
    if (vectorVariant.empty())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }
    bool result;
    for (std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> &variants : vectorVariant)
    {
        if (std::holds_alternative<std::shared_ptr<ICECar>>(variants))
        {
            std::shared_ptr<ICECar> h = std::get<0>(variants);
            if (h->fuelTankCapacity() <= 30)
            {
                result = false;
                break;
            }
            else
            {
                result = true;
            }
        }
    }
    return result;
}

int CountEvCarInstances(std::vector<std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>>> &vectorVariant)
{
    if (vectorVariant.empty())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }    
        int count = 0;
        for (std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> &variants : vectorVariant)
        {
            if (std::holds_alternative<std::shared_ptr<EvCar>>(variants))
            {
                count++;
            }
        }
    
        return count;
}

ChassisType ByChassisType(std::vector<std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>>> &vectorVariant, int id)
{
    if (vectorVariant.empty())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }
    ChassisType res;
    for (std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> &variants : vectorVariant)
    {
        if (std::holds_alternative<std::shared_ptr<EvCar>>(variants))
        {
            std::shared_ptr<EvCar> h = std::get<1>(variants);
            if (h->id() == id)
            {
                res = h->chassisType();
            }
        }
    }

    return res;
}

float TotalBatteryCapacity(std::vector<std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>>> &vectorVariant)
{
    if (vectorVariant.empty())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }
    float res=0.0f;
    for (std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> &variants : vectorVariant)
    {
        if (std::holds_alternative<std::shared_ptr<EvCar>>(variants))
        {
            std::shared_ptr<EvCar> h = std::get<1>(variants);
            res += h->batteryCapacity();
        }
    }
    if(res=0.0f)
    {
        throw NoMatchingInstanceException("No Matching exception\n");
    }
    return res;
}

std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>> ReturnNInstance(std::vector<std::variant<std::shared_ptr<ICECar>, std::shared_ptr<EvCar>>> &vectorVariant,int N)
{
    if (vectorVariant.empty())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }
    if(N>vectorVariant.size())
    {
        throw EmptyContainerException("EmptyContainer\n");
    }
    return vectorVariant[N];
}

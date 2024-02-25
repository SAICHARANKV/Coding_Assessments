#include "Functionalities.h"

void CreateObjects(VehicleConatiner &vehicleData, MotorContainer &motorData)
{
    std::string id;
    std::string model;
    int batteryType;
    float batteryCapacity;
    float time;
    float power;
    int torque;

    B:
    for(int i=0;i<4;i++)
    {
        std::cout<<"Enter time:";
        std::cin>>time;
        std::cout<<"Enter power:";
        std::cin>>power;
        std::cout<<"Enter torque:";
        std::cin>>torque;
        if(time<0||power<0||torque<0||power>400)
        {
            std::cout<<"Inputs cannot negative or max power cannot above 400"<<"\n";
            goto B;
            //CreateMotorObjects(motorData);
        }
        else
        {
            motorData.emplace_back(time,power,torque);
        }
    }

    auto itr=motorData.begin();

    A:
    for(int i=0;i<4;i++)
    {
        std::cout<<"Enter vehicle Id:";
        std::cin>>id;
        std::cout<<"Enter model:";
        std::cin>>model;
        std::cout<<"Enter battery type:";
        std::cin>>batteryType;
        std::cout<<"Enter battery capacity:";
        std::cin>>batteryCapacity;

        if(batteryType<0|| batteryCapacity>80.0)
        {
            std::cout<<"Inputs cannot negative or battery capacity cannot above 80.0"<<"\n";
            goto A;
            //CreateObjects(vehicleData,motorData);
        }
        else
        {
            vehicleData.emplace_back(
                std::make_shared<ElectricVehicle>(
                    id,
                    model,
                    static_cast<BatteryType>(batteryType),
                    batteryCapacity,
                    *itr++
                )
            );
        }
    }  
}

int FindMaxTorqueById(VehicleConatiner &vehicleData,std::string id)
{
    if(vehicleData.empty())
    {
        throw EmptyContainerException("Container is Empty!!!");
    }
   
    int torque;
    for(VehiclePointer& ptr:vehicleData)
    {
        if(ptr->vehicleId()==id)
        {
            if(ptr->batteryCapacity()>30.3)
            {
                torque=ptr->motor().get().maxTorque();
                break;
            }
        }
    }
    return torque;
}

float CalculateBatteryDrainPercentageByBatteryType(VehicleConatiner &vehicleData)
{
    if(vehicleData.empty())
    {
        throw EmptyContainerException("Container is Empty!!!");
    }

    float battteyDrain;
    for(VehiclePointer& ptr:vehicleData)
    {
        if(ptr->batteryType()==BatteryType::LITHIUM_ION)
        {
            battteyDrain= ptr->batteryCapacity()*0.10;
        }
        else
        {
            battteyDrain= (0.1*ptr->motor().get().maxTorque())+(0.2*ptr->motor().get().maxPower());
        }
    }

    return battteyDrain;
}

VehicleConatiner FilterData(VehicleConatiner &vehicleData, std::function<bool(int)> fn)
{
     if(vehicleData.empty())
    {
        throw EmptyContainerException("Container is Empty!!!");
    }
    VehicleConatiner result;
    for(VehiclePointer& ptr:vehicleData)
    {
        if(fn(ptr->motor().get().maxTorque()))
        {
            result.emplace_back(ptr);
        }
    }
    return result;
}

float FindMaxPowerOf2Instances(VehiclePointer &data1, VehiclePointer &data2)
{
    return *data1+*data2;
}
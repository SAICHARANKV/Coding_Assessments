#include"Functionalities.h"
#include<functional>

int main()
{
    VehicleConatiner vehicleData;
    MotorContainer motorData;

    CreateObjects(vehicleData,motorData);

    try
    {
        std::cout<<"MaxTorque:"<<FindMaxTorqueById(vehicleData,"v101")<<"\n";
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"-----------------------------------------------------------------"<<"\n";
    try
    {
        std::cout<<"Battery drain percentage:"<<CalculateBatteryDrainPercentageByBatteryType(vehicleData)<<"\n";
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"-----------------------------------------------------------------"<<"\n";
    try
    {
        auto fn= [](int torque)->bool {
                if(torque>50)
                    return true;
                else
                    return false;
            };
        VehicleConatiner result=FilterData(vehicleData,fn);
        std::cout<<"Electric vehicle details:"<<"\n";
        for(VehiclePointer& ptr:result)
        {
            std::cout<<*ptr;
        }
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"-----------------------------------------------------------------"<<"\n";
   
    std::cout<<"Maximum power of 2 instances:"<<FindMaxPowerOf2Instances(vehicleData[0],vehicleData[3]);








    return 0;
}
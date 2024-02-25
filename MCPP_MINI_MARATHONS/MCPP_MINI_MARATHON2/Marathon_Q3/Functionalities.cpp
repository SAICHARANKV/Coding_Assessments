#include "Functionalities.h"

void CreateObjects(FlightConatiner &flighData, PlaneConatiner &palneData)
{
    palneData.emplace_back(std::make_shared<Plane>("p101",PlaneType::JUMBO,200));
    palneData.emplace_back(std::make_shared<Plane>("p102",PlaneType::LUXURY,250));
    
    flighData.emplace_back(std::make_shared<Flight>(180,4000,palneData[0]));
    flighData.emplace_back(std::make_shared<Flight>(150,3000,palneData[1]));  
}

void Operation(const FlightConatiner &data, FnContainer &fns)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data Container is Empty!!!");
    }

    if(fns.empty())
    {
        throw FunctionConatinerException("FUnction conatiner is empty!!!");
    }

    for(FnType& fn:fns)
    {
        fn(data);
    }
}
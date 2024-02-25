#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include<memory>
#include"Flight.h"
#include<vector>
#include<functional>
#include "EmptyContainerException.h"
#include "FunctionContainerException.h"


using FlightPointer=std::shared_ptr<Flight>;

using PlanePointer=std::shared_ptr<Plane>;

using FlightConatiner=std::vector<FlightPointer>;

using PlaneConatiner=std::vector<PlanePointer>;

using FnType=std::function<void(const FlightConatiner&)>;

using FnContainer=std::vector<FnType>;

void CreateObjects(FlightConatiner& flighData,PlaneConatiner& palneData);

void Operation(const FlightConatiner& data,FnContainer& fns);

#endif // FUNCTIONALITIES_H
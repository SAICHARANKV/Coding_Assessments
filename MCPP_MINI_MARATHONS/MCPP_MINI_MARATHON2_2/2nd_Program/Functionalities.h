#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H


#include"TrainTicket.h"
#include"Train.h"
#include<memory>
#include<optional>

void CreateObjects(std::vector<TrainTicket>& vectorTrainTicket,
std::vector<std::shared_ptr<Train>>& vectorTrainPointer);

std::optional<int> CountOfTrainInstances(std::vector<std::shared_ptr<Train>>& vectorTrainPointer);

std::optional<std::vector<Train>> ReturnTrainInstancesDepartureWithin3(std::vector<std::shared_ptr<Train>>& vectorTrainPointer,int departureTime);

std::optional<int> ReturnTotalPriceByTrainNumber(std::vector<std::shared_ptr<Train>>& vectorTrainPointer,std::string id);

std::optional<std::string> FindTrainStartingStationWithConditions(std::vector<std::shared_ptr<Train>>& vectorTrainPointer);
#endif // FUNCTIONALITIES_H

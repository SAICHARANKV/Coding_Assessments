#include "Train.hpp"
#include <memory>
#include <variant>
#include <functional>
using TrainPointer = std::shared_ptr<Train>;
using Container =std::vector<TrainPointer>;
using TTPointer = std::shared_ptr<TrainTicket>;
using TTContainer = std::vector<TTPointer>;

void CreateObjects(Container &data, TTContainer &TTdata);

int CountTrainInstances(Container &data);
std::optional<std::vector<TrainPointer>> DepartureInNext3HoursByUser(Container &data, int x);
std::optional<float> TotalTicketPriceByTrainNumber(Container &data, std::string TrainNum);
std::string FindTrainStartingByNumberAndConditions(Container &data, std::string TrainNum);

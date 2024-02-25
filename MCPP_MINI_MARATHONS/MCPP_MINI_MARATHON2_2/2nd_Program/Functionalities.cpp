#include "Functionalities.h"
#include "EmptyContainerException.h"

void CreateObjects(std::vector<TrainTicket> &vectorTrainTicket,
                   std::vector<std::shared_ptr<Train>> &vectorTrainPointer)
{
    vectorTrainTicket.push_back(TrainTicket(3000.0f, TicketType::GENERAL, TicketClassType::AC));
    vectorTrainTicket.push_back(TrainTicket(2000.0f, TicketType::RESERVED, TicketClassType::FIRST));
    vectorTrainTicket.push_back(TrainTicket(5000.0f, TicketType::WAITING, TicketClassType::SECOND));

    vectorTrainPointer.push_back(
        std::make_shared<Train>(
            "100", "Pune", "Mumbai", 41, 40, vectorTrainTicket));

}

std::optional<int> CountOfTrainInstances(std::vector<std::shared_ptr<Train>> &vectorTrainPointer)
{
    if (vectorTrainPointer.empty())
    {
        throw EmptyContainerException("Empty container\n");
    }
    int count = 0;
    for (std::shared_ptr<Train> &trainPointer : vectorTrainPointer)
    {
        if (trainPointer->vectorTrainTicket().size() >= 3)
        {
            count++;
        }
    }
    if (count == 0)
    {
        return std::nullopt;
    }
    return count;
}

std::optional<std::vector<Train>>
ReturnTrainInstancesDepartureWithin3(std::vector<std::shared_ptr<Train>> &vectorTrainPointer,
                                     int departureTime)
{
    if (vectorTrainPointer.empty())
    {
        throw EmptyContainerException("Empty container\n");
    }

    std::vector<Train> result;
    for (std::shared_ptr<Train> &trainPointer : vectorTrainPointer)
    {
        int store = trainPointer->trainDepartureMinute();
        int store1 = trainPointer->trainDepartureHour();
        if (store1 == store + 1 || store1 == store + 2 || store1 == store + 3)
        {
            result.push_back(*trainPointer);
        }
    }
    if (result.empty())
    {
        return std::nullopt;
    }
    return result;
}

std::optional<int> ReturnTotalPriceByTrainNumber(std::vector<std::shared_ptr<Train>> &vectorTrainPointer,
                                                 std::string id)
{
    if (vectorTrainPointer.empty())
    {
        throw EmptyContainerException("Empty container\n");
    }
    int count = 0;
    for (std::shared_ptr<Train> &trainPointer : vectorTrainPointer)
    {
        if (trainPointer->trainNumber() == id)
        {
            count++;
        }
    }
    if (count == 0)
    {
        return std::nullopt;
    }
    return count;
}

std::optional<std::string> FindTrainStartingStationWithConditions(std::vector<std::shared_ptr<Train>> &vectorTrainPointer)
{
    if (vectorTrainPointer.empty())
    {
        throw EmptyContainerException("Empty container\n");
    }
    std::string res;
    for (std::shared_ptr<Train> &trainPointer : vectorTrainPointer)
    {    
        float total = 0.0f;
        for (int i = 0; i < trainPointer->vectorTrainTicket().size(); i++)
        {
            total += trainPointer->vectorTrainTicket()[i].ticketPrice();
        }

        if (trainPointer->trainDepartureHour() == 15 || trainPointer->trainDepartureHour() == 16 && total >= 2000)
        {
            res = trainPointer->trainStartingStation();
        }
    }
    if (res.empty())
    {
        return std::nullopt;
    }
    return res;
}

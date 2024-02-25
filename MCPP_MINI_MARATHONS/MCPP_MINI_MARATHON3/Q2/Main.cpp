#include <iostream>
#include "Functionalities.hpp"

int main()
{
    TTContainer TTdata;
    Container data;

    CreateObjects(data, TTdata);
    int ans = CountTrainInstances(data);
    std::cout << "____________\n";
    std::cout << "Trains Counts with more than 3 tickets: " << ans << "\n";
    std::cout << "____________\n";
    std::optional<std::vector<TrainPointer>> result = DepartureInNext3HoursByUser(data, 14);
    std::cout << "Next Trains Depatures in 3 Hours : "
              << "\n";

    if (result.has_value())
    {
        for (auto ele : result.value())
        {
            std::cout << *ele << "\n";
        }
    }

    std::cout << "____________\n";
    std::cout << "Total Ticket Price By Train Number : "
              << "\n";
    if (TotalTicketPriceByTrainNumber(data, "12345").has_value())
        std::cout << TotalTicketPriceByTrainNumber(data, "12345").value() << "\n";
    std::cout << "____________\n";
    std::cout << "Train Starting station for Train Num and and conditions\n";
    std::string s = FindTrainStartingByNumberAndConditions(data, "12345");
    std::cout << s << "\n";
    std::cout << "____________\n";
}
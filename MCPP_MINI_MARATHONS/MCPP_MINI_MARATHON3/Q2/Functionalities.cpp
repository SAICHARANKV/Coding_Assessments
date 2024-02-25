#include "Functionalities.hpp"
#include <algorithm>
#include <numeric>

void CreateObjects(Container &data, TTContainer &TTdata)
{
    TTdata.emplace_back(std::make_shared<TrainTicket>(
        2500.0f,
        TicketType::RESERVED,
        TicketClass::AC));
    TTdata.emplace_back(std::make_shared<TrainTicket>(3500.0f,
                                                      TicketType::WAITING,
                                                      TicketClass::AC));
    TTdata.emplace_back(std::make_shared<TrainTicket>(4500.0f,
                                                      TicketType::RESERVED,
                                                      TicketClass::SLEEPER));

    data.emplace_back(std::make_shared<Train>("123", "KNL", "HYD", 15, 10));
    data.emplace_back(std::make_shared<Train>("1234", "KNL", "TPT", 16, 12));

    data.emplace_back(std::make_shared<Train>(
        "12345",
        "KNL",
        "BLR",
        16,
        30, TTdata));
    data.emplace_back(std::make_shared<Train>("1234", "HYD", "PUNE", 18, 22, TTdata));
    TTdata.emplace_back(std::make_shared<TrainTicket>(
        9000,
        TicketType::GENERAL,
        TicketClass::SLEEPER));
}

int CountTrainInstances(Container &data)
{
    // int count = 0;
    // for (const auto &ele : data)
    // {
    //     if (ele->trainBookedTickets().size() >= 3)
    //     {
    //         count++;
    //     }
    // }
    int count = std::count_if(data.begin(), data.end(), [](TrainPointer &ptr)
                              { return ptr->trainBookedTickets().size() >= 3; });
    return count;
}

// std::optional<std::vector<TrainPointer>> DepartureInNext3HoursByUser(Container &data, int x)
// {
//     std::vector<TrainPointer> ss;
//     std::vector<int> times{x + 1, x + 2, x + 3};
//     for (const auto &ele : data)
//     {
//         auto ans = ele->trainDepartureHour();
//         for (int ans : times)
//         {
//
//             ss.emplace_back(ele);
//             break;
//         }
//     }
//     if (ss.empty())
//         return std::nullopt;
//     return ss;
// }

std::optional<std::vector<TrainPointer>> DepartureInNext3HoursByUser(Container &data, int x)
{
    std::vector<TrainPointer> ss;
    std::vector<int> times{x + 1, x + 2, x + 3};

    for (const auto &ele : data)
    {
        int departureHour = ele->trainDepartureHour();
        if (std::find(times.begin(), times.end(), departureHour) != times.end())
        {
            ss.push_back(ele);
        }
    }

    if (ss.empty())
        return std::nullopt;

    return ss;
}

std::optional<float> TotalTicketPriceByTrainNumber(Container &data, std::string TrainNum)
{
    float sum = 0.0f;
    for (const auto &ele : data)
    {
        if (ele->trainNumber() == TrainNum)
        {
            auto ans = ele->trainBookedTickets();
            for (auto val : ans)
            {
                sum += val->ticketPrice();
            }
        }
    }
    
    if (sum == 0.0f)
        return std::nullopt;
    return sum;
}

std::string FindTrainStartingByNumberAndConditions(Container &data, std::string TrainNum)
{
    float sum = 0.0f;
    std::string s;
    for (const auto &ele : data)
    {
        auto ans = ele->trainBookedTickets();

        for (auto val : ans)
        {
            sum += val->ticketPrice();
        }
    }

    for (const auto &ele : data)
    {
        if (ele->trainNumber() == TrainNum)
        {
            if ((ele->trainDepartureHour() == 15 || ele->trainDepartureHour() == 16) && (sum >= 2000))
            {
                s = ele->trainStartingStation();
            }
        }
    }
    return s;
}

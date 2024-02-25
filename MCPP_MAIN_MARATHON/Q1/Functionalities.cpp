#include "Functionalities.hpp"

void CreateObjects(Container &data)
{
    data[0] = std::make_shared<Automobile>("1", "Tata", AutomobileType::DEFENSE, 250000.0f, "PANZER");
    data[1] = std::make_shared<Automobile>("2", "Mahindra", AutomobileType::TRANSPORT, 150000.0f, "THAR");
    data[2] = std::make_shared<Automobile>("3", "BMW", AutomobileType::PRIVATE, 450000.0f, "X5");
}

std::optional<float> DisplayGreenPassCostById(Container &data, std::string id)
{
    if (data.empty())
        throw EmptyContainerException("Empty Data\n");

    auto itr = std::find_if(data.begin(), data.end(), [=](const AutomobilePointers &ptr)
                            { return (ptr->id() == id); });

    if (itr == data.end())
    {
        return std::nullopt;
    }
    return (*itr)->GreenPassCost();
}

float AveragePrice(Container &data)
{
    if (data.empty())
        throw EmptyContainerException("Empty Data\n");

    float ans = std::accumulate(data.begin(), data.end(), 0.0f,
                                [](int total, const AutomobilePointers &ptr)
                                {
                                    return total + ptr->price();
                                });
    return ans / data.size();
}

std::vector<PrivilegeCategory> FindPrivilegeType(Container &data)
{
    std::vector<PrivilegeCategory>p;
    if (data.empty())
        throw EmptyContainerException("Empty Data\n");
    for (AutomobilePointers &ptr : data)
    {
        p.emplace_back(ptr->FindPrivilegeType());
    }
    return p;
}

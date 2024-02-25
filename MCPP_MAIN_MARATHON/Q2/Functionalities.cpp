#include "Functionalities.hpp"
#include <numeric>

void CreateObjects(VehicleContainer &vdata, MapContainer &data)
{
    vdata.emplace_back(std::make_shared<Vehicle>("1", 34,
                                                 (std::make_shared<ServiceRecord>("101",
                                                                                  ServiceRecordType::REGULAR,
                                                                                  7,
                                                                                  550.0f,
                                                                                  "Sai",
                                                                                  "PUNE"))));
    vdata.emplace_back(std::make_shared<Vehicle>("2", 45,
                                                 (std::make_shared<ServiceRecord>("102",
                                                                                  ServiceRecordType::REPAIR,
                                                                                  15,
                                                                                  1550.0f,
                                                                                  "Surya",
                                                                                  "BLR"))));
    vdata.emplace_back(std::make_shared<Vehicle>("3", 22,
                                                 (std::make_shared<ServiceRecord>("103",
                                                                                  ServiceRecordType::REGULAR,
                                                                                  8,
                                                                                  550.0f,
                                                                                  "Dolly",
                                                                                  "KNL"))));
    vdata.emplace_back(std::make_shared<Vehicle>("4", 105,
                                                 (std::make_shared<ServiceRecord>("104",
                                                                                  ServiceRecordType::REPAIR,
                                                                                  56,
                                                                                  3000.0f,
                                                                                  "ND",
                                                                                  "BLR"))));
    vdata.emplace_back(std::make_shared<Vehicle>("5", 45,
                                                 (std::make_shared<ServiceRecord>("105",
                                                                                  ServiceRecordType::REGULAR,
                                                                                  7,
                                                                                  550.0f,
                                                                                  "Lavanya",
                                                                                  "CHTR"))));

    // Map Accepts Inputs
    data.emplace(std::make_pair(vdata[0]->vehicleId(), std::move(vdata[0])));
    data.emplace(std::make_pair(vdata[1]->vehicleId(), std::move(vdata[1])));
    data.emplace(std::make_pair(vdata[2]->vehicleId(), std::move(vdata[2])));
    data.emplace(std::make_pair(vdata[3]->vehicleId(), std::move(vdata[3])));
    data.emplace(std::make_pair(vdata[4]->vehicleId(), std::move(vdata[4])));
}
void LastNInstances(MapContainer &data, int n)
{
    if (data.empty())
        throw EmptyContainerException("Empty Data!!!!\n");
    int count = 0;
    // MapContainer temp(data.size());

    // std::copy(data.end(), data.begin(), temp.begin());
    std::for_each(data.cbegin(), data.cend(), [&](std::pair<std::string, VehiclePointers> &&ptr)
                  { if(count!=n){
                    std::cout<< *(ptr.second)<<"\n";
                  std::cout<<"-----------\n";  count++;} });
}

std::vector<std::pair<std::string, std::string>> ReturnListInstances(std::list<std::string> &ids, MapContainer &data)
{
    if (data.empty() || ids.empty())
        throw EmptyContainerException("Empty Data or ID list!!!!\n");

    std::vector<std::pair<std::string, std::string>> s;

    for (const auto &id : ids)
    {
        auto it = data.find(id);
        if (it != data.end())
        {
            auto &ptr = it->second;

            std::string vehicleId = ptr->vehicleId();
            std::string serviceId = ptr->latestServiceRecord()->serviceId();

            // Emplace the pair into the vector
            s.emplace_back(vehicleId, serviceId);
        }
    }

    return s;
}

std::pair<std::string, ServicePointers> MaxServiceChargeInList(MapContainer &data)
{
    if (data.empty())
        throw EmptyContainerException("Empty Data!!!!\n");
    float max = 0.0f;
    for (auto &ele : data)
    {
        max = ele.second->latestServiceRecord().get()->charges();
        if (ele.second->latestServiceRecord().get()->charges() > max)
            max = ele.second->latestServiceRecord().get()->charges();
    }

    auto itr = std::find_if(data.begin(), data.end(), [&](std::pair<std::string, VehiclePointers> &&ptr)
                            { return max; });

    return std::pair<std::string, ServicePointers>((*itr).second->vehicleId(), (*itr).second.get()->latestServiceRecord());
}

float ReturnRegularAverageServiceCharge(MapContainer &data)
{
    if (data.empty())
        throw EmptyContainerException("Empty Data!!!!\n");
    std::vector<std::pair<std::string, VehiclePointers>> s(data.size());
    auto itr = std::copy_if(data.begin(), data.end(), s.begin(), [&](std::pair<std::string, VehiclePointers> &&ptr)
                            {
        if(ptr.second.get()->latestServiceRecord().get()->type()==ServiceRecordType::REGULAR)
            return true;
        return false; });
    size_t newsize = std::distance(s.begin(), itr);
    s.resize(newsize);
    float ans = std::accumulate(s.begin(), s.end(), 0.0f, [](float total, const std::pair<std::string, VehiclePointers> &ptr)
                                { return total + ptr.second.get()->latestServiceRecord().get()->charges(); });
    return ans / s.size();
}

std::string VehicleIdByServiceId(MapContainer &data, std::string sid)
{
    if (data.empty())
        throw EmptyContainerException("Empty Data!!!!\n");
    auto itr = std::find_if(data.begin(), data.end(), [&](std::pair<std::string, VehiclePointers> &&ptr)
                            { return ptr.second.get()->latestServiceRecord().get()->serviceId() == sid; });
    return (*itr).first;
}

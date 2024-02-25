#include "Functionalities.hpp"
#include <list>
int main()
{
    VehicleContainer vdata;
    MapContainer data;

    // Create Objects
    CreateObjects(vdata, data);
    std::cout << "Objects Successfuly Created\n";
    std::cout << "----------\n";
    std::cout << "Return Last N instances: \n";
    try
    {
        LastNInstances(data, 3);
        std::cout << "----------\n";
        std::cout << "Returning List Instances: \n";
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::list<std::string> ids = {"1", "2", "4"};
        std::vector<std::pair<std::string, std::string>> res = ReturnListInstances(ids, data);

        for (auto &ele : res)
        {
            std::cout << ele.first << " : " << ele.second << "\n";
        }

        std::cout << "----------\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Return Max Pair in list:\n";
    try
    {
        std::pair<std::string, ServicePointers> s = MaxServiceChargeInList(data);
        std::cout << s.first << ": " << *(s.second) << "\n";
        std::cout << "----------\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Average Regular Charges: " << ReturnRegularAverageServiceCharge(data) << "\n";
        std::cout << "----------\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Vehicle Id by Service Id: " << VehicleIdByServiceId(data, "101") << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cerr << e.what() << '\n';
    }
}
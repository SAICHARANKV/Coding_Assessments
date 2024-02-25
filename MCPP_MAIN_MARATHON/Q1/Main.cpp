#include "Functionalities.hpp"
#include <iostream>
int main()
{
    // Empty Container
    Container data;

    // Create Objects
    CreateObjects(data);
    std::cout << "Objects Successfuly Created\n";

    std::cout << "________\n";
    try
    {
        float ans;
        if (DisplayGreenPassCostById(data, "1").has_value())
            ans = DisplayGreenPassCostById(data, "1").value();
        std::cout << "Green Pass Cost By ID: " << ans << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "________\n";
    try
    {
        std::cout << "Average Price of instances: \n"
                  << AveragePrice(data) << "\n";
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "________\n";
    try
    {
        std::cout << "Privilage Categorys: \n";
        std::vector<PrivilegeCategory> p = FindPrivilegeType(data);
        for (PrivilegeCategory &ptr : p)
        {
            std::cout << static_cast<int>(ptr) << "\n";
        }
    }
    catch (EmptyContainerException &e)
    {
        std::cout << e.what() << '\n';
    }
}
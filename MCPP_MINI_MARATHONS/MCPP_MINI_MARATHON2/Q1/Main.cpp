#include <iostream>
#include "Functionalities.hpp"
#include "EmptyContainerException.hpp"
#include "NoInstanceFoundException.hpp"
#include "DataSizeException.hpp"

int main()
{
    DataContainer data{"xyz", "abcd", "efghi"};
    FnContainer fns; // Empty FnContainer

    // Calling Lambda Function
    try
    {
        MakeLambdas(data, fns);
    }
    catch (EmptyContainerException ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch (DataSizeException ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch (NoInstanceFoundException ex)
    {
        std::cout << ex.what() << "\n";
    }

    // Output operations on lambda container
    try
    {
        PerformOperation(data, fns);
    }
    catch (EmptyContainerException ex)
    {
        std::cout << ex.what() << "\n";
    }
}
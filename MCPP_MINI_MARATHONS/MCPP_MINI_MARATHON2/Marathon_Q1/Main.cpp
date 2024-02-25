#include "Functionalities.h"
#include <vector>
#include <iostream>

int main()
{
    FnContainer fns;
    CreateData(fns);
    std::vector<int> data = {3, 9, 15, 18, 24 };
    PerformOperation(fns,data); 
}
#include <iostream>
#include <vector>
#include <functional>

using Container = std::function<int(std::vector<int>&)>;
using FnContainer = std::vector<Container>;

extern Container TotalOddSumOf3 ;

extern Container LowestEvenNumer ;

extern Container MaxValue ;


void CreateData(FnContainer& fns);

void PerformOperation(FnContainer& fns,  std::vector<int>& data);
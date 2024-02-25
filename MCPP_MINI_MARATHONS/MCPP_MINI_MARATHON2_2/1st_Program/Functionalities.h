#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<functional>
#include<vector>
#include<future>
#include<array>

void MakeLambda(std::vector<std::function<void(std::array<int, 5>)>> &functions);
extern std::function<void(std::array<int,5>)> PrintSumOfFirstNIntegers;
extern std::function<void(std::array<int,5>)> DisplayEven;
extern std::function<void(std::array<int,5>)> SquareOfEach;
extern std::function<void(std::array<int,5>)> CubeOfEach;

std::array<int,5> GenerateFiveIntegers(std::future<int>& input);


void JoinOfThreads(std::array<std::thread,4>& arrThreads);

void MappingThreads(std::vector<std::function<void(std::array<int, 5>)>> &functions,
std::array<std::thread,4>& arrThreads,std::array<int,5>& data);




#endif // FUNCTIONALITIES_H

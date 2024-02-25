#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include <functional>
#include <string>
#include <iostream>
using FnType = std::function<std::string(std::vector<std::string>&)>;
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<std::string>;

void MakeLambdas(DataContainer &data, FnContainer &fns);
void PerformOperation(DataContainer &data, FnContainer &fns);

#endif // FUNCTIONALITIES_HPP

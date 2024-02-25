#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP
#include <memory>
#include <variant>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <thread>
#include <future>
#include "Employee.hpp"
#include "BusinessOwner.hpp"
#include "EmptyContainerException.hpp"
using EmployeePointer = std::shared_ptr<Employee>;
using BusinessPointer = std::shared_ptr<BusinessOwner>;
using Container = std::vector<std::variant<EmployeePointer, BusinessPointer>>;
using ThreadArray = std::array<std::thread, 2>;

void CreateObjects(Container &data);
void CountBussinessOwners(Container &data, int age);
void TaxableAmountAboveThreshold(Container &data, int amt);
void ThreadMapping(Container &data, ThreadArray &arr);
void TaxPercentBelowThreshold(Container &data, std::future<int> &ft);
void JoinThreads(ThreadArray &arr);

#endif // FUNCTIONALITIES_HPP

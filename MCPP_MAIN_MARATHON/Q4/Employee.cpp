#include "Employee.hpp"

Employee::Employee(unsigned long id, std::string name, EmployeeType type, int age, int taxable_amount, int tax_percent)
    : _reg_id(id), _name(name), _type(type), _age(age), _taxableamount(taxable_amount), _tax_percent(tax_percent)
{
}
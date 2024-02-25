#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include "EmployeeType.hpp"
#include <string>
class Employee
{
private:
    unsigned long _reg_id;
    std::string _name;
    EmployeeType _type;
    int _age{17};
    int _taxableamount;
    int _tax_percent{5};

public:
    /* Special Enablers and disablers */
    Employee() = delete;
    Employee(const Employee &) = default;
    Employee(Employee &&) = delete;
    Employee &operator=(const Employee &) = default;
    Employee &operator=(Employee &&) = default;
    ~Employee() = default;

    /* Getter and Setters */
    unsigned long regId() const { return _reg_id; }
    void setRegId(unsigned long reg_id) { _reg_id = reg_id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    EmployeeType type() const { return _type; }
    void setType(const EmployeeType &type) { _type = type; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    int taxableamount() const { return _taxableamount; }
    void setTaxableamount(int taxableamount) { _taxableamount = taxableamount; }

    int taxPercent() const { return _tax_percent; }
    void setTaxPercent(int tax_percent) { _tax_percent = tax_percent; }

    /* Parameterized Constructor */
    Employee(unsigned long id, std::string name, EmployeeType type, int age, int taxable_amount, int tax_percent);
};

#endif // EMPLOYEE_HPP

#ifndef BUSINESSOWNER_HPP
#define BUSINESSOWNER_HPP

#include "BusinessType.hpp"
#include <string>
class BusinessOwner
{
private:
    unsigned short _reg_id;
    std::string _name;
    BusinessType _type;
    int _age{18};
    int _taxableamount;
    int _tax_percent{15};

public:
    /* Special Enablers and disablers */
    BusinessOwner() = delete;
    BusinessOwner(const BusinessOwner &) = default;
    BusinessOwner(BusinessOwner &&) = delete;
    BusinessOwner &operator=(const BusinessOwner &) = default;
    BusinessOwner &operator=(BusinessOwner &&) = default;
    ~BusinessOwner() = default;

    /* Getter and Setters */
    unsigned long regId() const { return _reg_id; }
    void setRegId(unsigned long reg_id) { _reg_id = reg_id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    BusinessType type() const { return _type; }
    void setType(const BusinessType &type) { _type = type; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    int taxableamount() const { return _taxableamount; }
    void setTaxableamount(int taxableamount) { _taxableamount = taxableamount; }

    int taxPercent() const { return _tax_percent; }
    void setTaxPercent(int tax_percent) { _tax_percent = tax_percent; }

    /* Parameterized Constructor */
    BusinessOwner(unsigned short id, std::string name, BusinessType type, int age, int taxable_amount, int tax_percent);
};

#endif // BUSINESSOWNER_HPP

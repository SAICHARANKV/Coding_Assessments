#ifndef PERMIT_H
#define PERMIT_H
#include <string>
#include <ostream>
#include "PermitType.h"

class Permit
{
private:
    std::string _serial_number;
    PermitType _permit_type;
    int _permit_duration_left;

public:
    Permit() = delete;
    Permit(const Permit &) = default;
    Permit &operator=(const Permit &) = default;
    Permit(Permit &&) = delete; // Move constructor
    Permit &operator=(Permit &&) = delete;
    ~Permit() = default;

    Permit(std::string serialnumber, PermitType ptype, int durationleft);

    std::string serialNumber() const { return _serial_number; }
    void setSerialNumber(const std::string &serial_number) { _serial_number = serial_number; }

    PermitType permitType() const { return _permit_type; }
    void setPermitType(const PermitType &permit_type) { _permit_type = permit_type; }

    int permitDurationLeft() const { return _permit_duration_left; }
    void setPermitDurationLeft(int permit_duration_left) { _permit_duration_left = permit_duration_left; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H

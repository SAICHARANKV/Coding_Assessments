#ifndef HEADER_H
#define HEADER_H

#include <iostream>
enum rating
{
    POOR = 1,
    AVERAGE,
    GOOD,

};

class Hospital
{
    std::string Hospital_id;
    std::string Hospital_name;
    rating e;

public:
    rating getE() const { return e; }
    void setE(const rating &e_) { e = e_; }

    std::string hospitalName() const { return Hospital_name; }
    void setHospitalName(const std::string &hospitalName) { Hospital_name = hospitalName; }
    std::string hospitalId() const { return Hospital_id; }
    void setHospitalId(const std::string &hospitalId) { Hospital_id = hospitalId; }

    Hospital();
    Hospital(std::string s, std::string n, enum rating m);
    void accept();
    friend std::ostream &operator<<(std::ostream &os, Hospital &h);
};

class doctor : public Hospital
{
    std::string doctor_id;
    std::string doctor_name;
    std::string doctor_speciality;
    std::string register_hosiptal;
    float doctor_fees;

public:
    void calculatetax(float);
    doctor();
    void accept();
    doctor(std::string, std::string, std::string, std::string, float);
    friend std::ostream &operator<<(std::ostream &o,doctor &m);
};

#endif // HEADER_H

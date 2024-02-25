#include <iostream>
#include "header.h"

Hospital::Hospital()
{
    Hospital_id = "123";
    Hospital_name = "RAVI";
    e = GOOD;
}
Hospital::Hospital(std::string s, std::string n, enum rating m)
{
    Hospital_id = s;
    Hospital_name = n;
    e = m;
}

void Hospital::accept()
{
    std::cout<<"Hospitalid";
    std::cin >> Hospital_id;
    std::cout<<"Hospitalname";
    std::cin >> Hospital_name;
    int choice;
    std::cout << "1.Poor 2.Average 3.Good " << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        e = POOR;
        break;
    case 2:
        e = AVERAGE;
        break;
    case 3:
        e = GOOD;
        break;
    }
}
std::ostream &operator<<(std::ostream &os, Hospital &h)
{
    os << h.Hospital_id << " ";
    os << h.Hospital_name << " ";
    os << h.e << " ";
    return os;
}

std::ostream &operator<<(std::ostream &o, doctor &m)
{
    o << m.doctor_id << " ";
    o << m.doctor_name << " ";
    o << m.doctor_speciality << " ";
    o << m.register_hosiptal << " ";
    o << m.doctor_fees << " ";
    return o;
}

doctor::doctor()
{
    doctor_id = "1";
    doctor_name = "Sai";
    doctor_speciality = "Suregon";
    register_hosiptal = "1";
    doctor_fees = 3000;
    calculatetax(doctor_fees);
}

doctor::doctor(std::string did, std::string dname, std::string dspec, std::string reg, float dfee) : doctor_fees(dfee)
{
    doctor_id = did;
    doctor_name = dname;
    doctor_speciality = dspec;
    register_hosiptal = reg;
    calculatetax(doctor_fees);
}
void doctor::calculatetax(float doctor_fees)
{
    float amount = doctor_fees * 0.2;
    std::cout << "Tax = " << amount;
}
void doctor::accept()
{
    std::cout << "doctorid";
    std::cin >> doctor_id;
    std::cout << "doctorname";
    std::cin >> doctor_name;
}
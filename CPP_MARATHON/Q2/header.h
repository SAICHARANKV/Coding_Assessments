#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
enum carcategory
{
    SUV = 1,
    HATCHBACK,
    SEDAN
};
enum bikecategory
{
    COMMUTE = 1,
    SPORTS,
    OFFROADER
};

class vehicle
{
    int chassisnum;
    char vehiclebrand[20];
    double price;
    double tax;
    double insuranceamount;

public:
    ~vehicle(){};
    int getChassisnum() const { return chassisnum; }
    void setChassisnum(int chassisnum_) { chassisnum = chassisnum_; }

    char getVehiclebrand() const { return *vehiclebrand; }
    void setVehiclebrand(char *vehiclebrand_) { strcpy(vehiclebrand, vehiclebrand_); }

    double getPrice() const { return price; }
    void setPrice(double price_) { price = price_; }

    double getTax() const { return tax; }
    void setTax(double tax_) { tax = tax_; }

    double getInsuranceamount() const { return insuranceamount; }
    void setInsuranceamount(double insuranceamount_) { insuranceamount = insuranceamount_; }

    virtual void accept();
    virtual void display();
};
void noofvehicles(vehicle[], int);
void details(vehicle[], int);

class car : public vehicle
{
    carcategory cc;

public:
    void accept(car[], int);
    void display();

    carcategory getC() const { return cc; }
    void setC(const carcategory &c_) { cc = c_; }
};

class bike : public vehicle
{
    bikecategory bc;

public:
    void accept(bike[], int);
    void display();

    bikecategory getB() const { return bc; }
    void setB(const bikecategory &b_) { bc = b_; }
};
void avgpricebike(bike [], int size );
void avgpricecar(car [],int size);

#endif // HEADER_H

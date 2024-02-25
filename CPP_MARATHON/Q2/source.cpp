#include <iostream>
#include "header.h"
#include <cstring>
int carcount = 0;
int bikecount = 0;
float car_avg = 0, bike_avg = 0;
void vehicle::accept()
{
    std::cout << "Enter chassisnum ";
    std::cin >> chassisnum;
    std::cout << "Enter vehiclebrand ";
    std::cin >> vehiclebrand;
    std::cout << "Enter Ex-Show room price ";
    std::cin >> price;
    std::cout << "Enter Tax ";
    std::cin >> tax;
    std::cout << "Enter insuranceamount ";
    std::cin >> insuranceamount;
}
void details(vehicle a[], int n)
{
    std::cout << "Enter Chasis Number " << std::endl;
    int ele, count = 0;
    std::cin >> ele;
    for (int i = 0; i < n; i++)
    {
        if (a[i].getChassisnum() == ele)
            a[i].display();
        count = 1;
    }
    if (count == 0)
        std::cout << "No Vehicle found\n";
}

void vehicle::display()
{
    std::cout << "Chasis number\t" << chassisnum << std::endl;
    std::cout << "Vehicle brand\t" << vehiclebrand << std::endl;
    std::cout << "Price\t" << price << std::endl;
    std::cout << "Tax\t" << tax << std::endl;
    std::cout << "Insurance amount\t" << insuranceamount << std::endl;
}

void noofvehicles(vehicle a[], int size)
{
    int count = 0, i = 0;
    while (i < size)
    {
        if (a[i].getPrice() >= 0)
            count++;
        i++;
    }
    std::cout << "No of vehicles" << count << "\n";
}

void avgpricebike(bike a[], int size)
{
    int sum = 0;
    float avg = 0;
    std::cout << "Enter element to be calculated\n";
    int s;
    std::cin >> s;
    for (int i = 0; i < size; i++)
    {
        if (a[i].getB() == s)
            sum = sum + a[i].getPrice();
    }
    avg = float(sum) / size;

    std::cout << "Average of bikes is\n"
              << avg << "\n";
}

void avgpricecar(car a[], int size)
{
    int sum = 0;
    float avg = 0;
    std::cout << "Enter element to be calculated\n";
    int s;
    std::cin >> s;
    for (int i = 0; i < size; i++)
    {
        if (a[i].getC() == s)
            sum = sum + a[i].getPrice();
    }
    avg = float(sum) / size;

    std::cout << "Average of cars is\n"
              << avg << "\n";
}

void car::accept(car a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter chassisnum ";
        int num;
        std::cin >> num;
        a[i].setChassisnum(num);
        std::cout << "Enter vehiclebrand ";
        char s[20];
        std::cin >> s;
        a[i].setVehiclebrand(s);
        std::cout << "Enter Ex-Show room price ";
        double p;
        std::cin >> p;
        a[i].setPrice(p);
        std::cout << "Enter Tax ";
        double t;
        std::cin >> t;
        a[i].setTax(t);
        std::cout << "Enter insuranceamount ";
        double m;
        std::cin >> m;
        a[i].setInsuranceamount(m);
        int chc;
        std::cout << "1.SUV 2.HATCHBACK 3.SEDAN" << std::endl;
        std::cin >> chc;
        switch (chc)
        {
        case 1:
            a[carcount].setC(SUV);
            carcount++;
            break;
        case 2:
            a[carcount].setC(HATCHBACK);
            carcount++;
            break;
        case 3:
            a[carcount].setC(SEDAN);
            carcount++;
            break;
        }
        break;
    }
}
void car::display()
{
    std::cout << "Chasis number\t" << getChassisnum() << std::endl;
    std::cout << "Vehicle brand\t" << getVehiclebrand() << std::endl;
    std::cout << "Price\t" << getPrice() << std::endl;
    std::cout << "Tax\t" << getTax() << std::endl;
    std::cout << "Insurance amount\t" << getInsuranceamount() << std::endl;
    std::cout << "Car Category selected\t" << getC() << std::endl;
}

void bike::accept(bike m[], int n)
{
    int bikecount = 0, sumb = 0;
    float bike_avg = 0;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter chassisnum ";
        int num;
        std::cin >> num;
        m[i].setChassisnum(num);
        std::cout << "Enter vehiclebrand ";
        char s[20];
        std::cin >> s;
        m[i].setVehiclebrand(s);

        std::cout << "Enter Ex-Show room price ";
        double p;
        std::cin >> p;
        m[i].setPrice(p);
        std::cout << "Enter Tax ";
        double t;
        std::cin >> t;
        m[i].setTax(t);
        std::cout << "Enter insuranceamount ";
        double z;
        std::cin >> z;
        m[i].setInsuranceamount(z);
        int ch;
        std::cout << "1.COMMUTE 2.SPORTS 3.OFFROADER" << std::endl;
        std::cin >> ch;
        switch (ch)
        {

        case 1:
            m[bikecount].setB(COMMUTE);
            bikecount++;
            break;
        case 2:
            m[bikecount].setB(SPORTS);
            bikecount++;
            break;
        case 3:
            m[bikecount].setB(OFFROADER);
            bikecount++;
            break;
        }
        break;
    }
}
void bike::display()
{
    std::cout << "Chasis number\t" << getChassisnum() << std::endl;
    std::cout << "Vehicle brand\t" << getVehiclebrand() << std::endl;
    std::cout << "Price\t" << getPrice() << std::endl;
    std::cout << "Tax\t" << getTax() << std::endl;
    std::cout << "Insurance amount\t" << getInsuranceamount() << std::endl;
    std::cout << "Bike category selected\t" << getB() << std::endl;
}
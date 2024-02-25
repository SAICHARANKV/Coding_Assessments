#include <iostream>
#include "header.h"
int main()
{
    vehicle *cptr = new car[5];
    vehicle *bptr = new bike[5];
    car *c = dynamic_cast<car *>(cptr);
    bike *b = dynamic_cast<bike *>(bptr);

    c->car::accept(c, 1);
    b->bike::accept(b, 1);
    std::cout << "Details of particular vehicle\n"
              << std::endl;
    details(c, 1);
    details(b, 1);
    std::cout << "\n";

    std::cout << "Count of vehicle category\n"
              << std::endl;
    noofvehicles(c, 1);
    noofvehicles(b, 1);

    std::cout << "\n";

    std::cout << "Average of vehicle category\n";
    avgpricecar(c, 1);
    avgpricebike(b, 1);
    std::cout << "\n";
}
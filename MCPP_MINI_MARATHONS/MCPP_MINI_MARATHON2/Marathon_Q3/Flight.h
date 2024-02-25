#ifndef FLIGHT_H
#define FLIGHT_H

#include<iostream>
#include"Plane.h"
#include<memory>
#include<functional>

using RefSharedType=std::reference_wrapper<std::shared_ptr<Plane>>;

class Flight
{
private:
    int _duration_minutes;
    float _ticket_price;
    RefSharedType _plane;

public:
//special member functions
    Flight()=delete;
    Flight(const Flight&)=delete;
    Flight& operator=(const Flight&)=delete;
    Flight(Flight&&)=delete;
    Flight& operator=(Flight&&)=delete;
    ~Flight()=default;

//getters and setters
    int durationMinutes() const { return _duration_minutes; }
    void setDurationMinutes(int duration_minutes) { _duration_minutes = duration_minutes; }

    float ticketPrice() const { return _ticket_price; }
    void setTicketPrice(float ticket_price) { _ticket_price = ticket_price; }
    
    RefSharedType plane() const { return _plane; }
    void setPlane(const RefSharedType &plane) { _plane = plane; }

//parameterized constructor
    Flight(int duration,float price,RefSharedType plane);
    
//member function
    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);   
};

#endif // FLIGHT_H
#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include"PlaneType.h"

class Plane
{
private:
    const std::string _planeId;
    const PlaneType _planeType;
    int _capacity;

public:
//special member function
    Plane()=delete;
    Plane(const Plane&)=delete;
    Plane& operator=(const Plane&)=delete;
    Plane(Plane&&)=delete;
    Plane& operator=(Plane&&)=delete;
    ~Plane()=default;

//getters and setters
    std::string planeId() const { return _planeId; }
    
    PlaneType planeType() const { return _planeType; }

    int capacity() const { return _capacity; }
    void setCapacity(int capacity) { _capacity = capacity; }

//parameterized constructor
    Plane(std::string id,PlaneType type,int capacity);

//Member functions
    friend std::ostream &operator<<(std::ostream &os, const Plane &rhs);  
};

#endif // PLANE_H
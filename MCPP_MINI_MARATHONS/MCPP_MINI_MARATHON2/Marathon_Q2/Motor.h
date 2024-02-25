#ifndef MOTOR_H
#define MOTOR_H

#include<iostream>

class Motor
{
private:
    float _motorTime;
    float _maxPower;
    int _maxTorque;
public:
//special member functions
    Motor()=delete;
    Motor(const Motor&)=default;
    Motor& operator=(const Motor&)=delete;
    Motor(Motor&&)=default;
    Motor& operator=(Motor&&)=delete;
    ~Motor()=default;

//getters and setters
    float motorTime() const { return _motorTime; }
    float maxPower() const { return _maxPower; }
    int maxTorque() const { return _maxTorque; }

//parameterized constructor
    Motor(float time,float maxPower,int maxTorque);

//Member functions
    float operator+(const Motor& m);
    friend std::ostream &operator<<(std::ostream &os, const Motor &rhs);
    
};

#endif // MOTOR_H
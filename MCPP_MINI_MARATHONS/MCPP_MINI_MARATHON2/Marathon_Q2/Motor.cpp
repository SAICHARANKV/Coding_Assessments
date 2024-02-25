#include"Motor.h"

std::ostream &operator<<(std::ostream &os, const Motor &rhs) {
    os << "_motorTime: " << rhs._motorTime
       << " _maxPower: " << rhs._maxPower
       << " _maxTorque: " << rhs._maxTorque;
    return os;
}

Motor::Motor(float time, float maxPower, int maxTorque)
    :_motorTime(time),_maxPower(maxPower),_maxTorque(maxTorque)
{
}

float Motor::operator+(const Motor &m)
{
    return _maxPower+m._maxPower;
}
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <list>
#include <vector>
#include "Sensor.h"

using SensorPointer = std::shared_ptr<Sensor>;
using SensorContainer = std::list<SensorPointer>;

void CreateObjects(SensorContainer &data);

bool ReadingAbove25(SensorContainer &data);

float AverageReadingBySensorType(SensorContainer &data, SensorType stype);

std::list<Sensor> DisplaySensorInstancesByConditions(SensorContainer &data);

#endif // FUNCTIONALITIES_H

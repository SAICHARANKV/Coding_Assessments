#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <functional>
#include <string>
#include <iostream>
#include <memory>
#include "ServiceRecord.hpp"

using ServRef = std::reference_wrapper<ServiceRecord>;
using ServicePointers = std::shared_ptr<ServiceRecord>;

class Vehicle
{
private:
    std::string _vehicle_id;
    int _active_duration_months;
    ServicePointers _latest_service_record;

public:
    /* Special Enablers and disablers */
    Vehicle() = delete;
    Vehicle(const Vehicle &) = default;
    Vehicle(Vehicle &&) = default;
    Vehicle &operator=(const Vehicle &) = default;
    Vehicle &operator=(Vehicle &&) = default;
    ~Vehicle() = default;

    /* Parameterized Constructor */
    Vehicle(std::string vid, int duration, ServicePointers record);

    /* Getter and Setters */
    std::string vehicleId() const { return _vehicle_id; }
    void setVehicleId(const std::string &vehicle_id) { _vehicle_id = vehicle_id; }

    int activeDurationMonths() const { return _active_duration_months; }
    void setActiveDurationMonths(int active_duration_months) { _active_duration_months = active_duration_months; }

    ServicePointers latestServiceRecord() const { return _latest_service_record; }
    void setLatestServiceRecord(const ServicePointers &latest_service_record) { _latest_service_record = latest_service_record; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_HPP

#ifndef SERVICERECORD_HPP
#define SERVICERECORD_HPP

#include <string>
#include <ostream>
#include "ServiceRecordType.hpp"

class ServiceRecord
{
private:
    std::string _service_id;
    ServiceRecordType _type;
    int _duration_hours;
    float _charges;
    std::string _service_attendant_name;
    std::string _service_location;

public:
    /* Special Enablers and disablers */
    ServiceRecord() = delete;
    ServiceRecord(const ServiceRecord &) = default;
    ServiceRecord(ServiceRecord &&) = default;
    ServiceRecord &operator=(const ServiceRecord &) = default;
    ServiceRecord &operator=(ServiceRecord &&) = default;
    ~ServiceRecord() = default;

    /* Parameterized Constructor */
    ServiceRecord(std::string id, ServiceRecordType type, int duration_hours, float charges, std::string attendant, std::string location);

    /* Getter and Setters */
    std::string serviceId() const { return _service_id; }
    void setServiceId(const std::string &service_id) { _service_id = service_id; }

    ServiceRecordType type() const { return _type; }
    void setType(const ServiceRecordType &type) { _type = type; }

    int durationHours() const { return _duration_hours; }
    void setDurationHours(int duration_hours) { _duration_hours = duration_hours; }

    float charges() const { return _charges; }
    void setCharges(float charges) { _charges = charges; }

    std::string serviceAttendantName() const { return _service_attendant_name; }
    void setServiceAttendantName(const std::string &service_attendant_name) { _service_attendant_name = service_attendant_name; }

    std::string serviceLocation() const { return _service_location; }
    void setServiceLocation(const std::string &service_location) { _service_location = service_location; }

    friend std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs);
};

#endif // SERVICERECORD_HPP

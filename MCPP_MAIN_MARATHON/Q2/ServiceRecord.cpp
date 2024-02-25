#include "ServiceRecord.hpp"
std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs)
{
    os << "_service_id: " << rhs._service_id
       << " _type: " << static_cast<int>(rhs._type)
       << " _duration_hours: " << rhs._duration_hours
       << " _charges: " << rhs._charges
       << " _service_attendant_name: " << rhs._service_attendant_name
       << " _service_location: " << rhs._service_location;
    return os;
}
ServiceRecord::ServiceRecord(std::string id, ServiceRecordType type, int duration_hours, float charges, std::string attendant, std::string location)
    : _service_id(id), _type(type), _duration_hours(duration_hours), _charges(charges), _service_attendant_name(attendant), _service_location(location)
{
}

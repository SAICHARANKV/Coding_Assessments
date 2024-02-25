#ifndef TRAINTICKET_HPP
#define TRAINTICKET_HPP
#include "TicketType.hpp"
#include "TicketClass.hpp"
#include <ostream>
class TrainTicket
{
private:
    float _ticketPrice{0};
    TicketType _ticketType{TicketType::GENERAL};
    TicketClass _ticketClass{TicketClass::AC};

public:
    /* Special Enablers and disablers */
    TrainTicket() = delete;
    TrainTicket(const TrainTicket &) = default;
    TrainTicket(TrainTicket &&) = delete;
    TrainTicket &operator=(const TrainTicket &) = default;
    TrainTicket &operator=(TrainTicket &&) = delete;
    ~TrainTicket() = default;

    /* Parameterized Constructor */
    TrainTicket(float ticketPrice, TicketType ticketType, TicketClass ticketClass);

    /* Getter and Setters */
    float ticketPrice() const { return _ticketPrice; }
    void setTicketPrice(float ticketPrice) { _ticketPrice = ticketPrice; }

    TicketType ticketType() const { return _ticketType; }
    void setTicketType(const TicketType &ticketType) { _ticketType = ticketType; }

    TicketClass ticketClass() const { return _ticketClass; }
    void setTicketClass(const TicketClass &ticketClass) { _ticketClass = ticketClass; }

    friend std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs);
};

#endif // TRAINTICKET_HPP

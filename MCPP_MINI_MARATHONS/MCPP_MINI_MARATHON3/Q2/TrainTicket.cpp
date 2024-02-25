#include "TrainTicket.hpp"

TrainTicket::TrainTicket(float ticketPrice, TicketType ticketType, TicketClass ticketClass)
    : _ticketPrice(ticketPrice), _ticketType(ticketType), _ticketClass(ticketClass)
{
}

std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs)
{
    os << "_ticketPrice: " << rhs._ticketPrice
       << " _ticketType: " << static_cast<int>(rhs._ticketType)
       << " _ticketClass: " << static_cast<int>(rhs._ticketClass);
    return os;
}

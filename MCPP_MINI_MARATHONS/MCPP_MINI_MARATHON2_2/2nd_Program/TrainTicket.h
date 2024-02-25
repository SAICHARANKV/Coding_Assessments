#ifndef TRAINTICKET_H
#define TRAINTICKET_H

#include"TicketClassType.h"
#include"TicketType.h"
#include <ostream>

class TrainTicket
{
private:
    float _ticketPrice;
    TicketType _ticketType;
    TicketClassType _ticketClassType;

public:
    TrainTicket()=default;
    TrainTicket(const TrainTicket&)=default;
    TrainTicket(TrainTicket&&)=default;
    TrainTicket& operator=(const TrainTicket&)=default;
    TrainTicket& operator=(TrainTicket&&)=default;
    ~TrainTicket()=default;

    TrainTicket(float ticketPrice,TicketType ticketType,TicketClassType ticketClassType);

    float ticketPrice() const { return _ticketPrice; }
    void setTicketPrice(float ticketPrice) { _ticketPrice = ticketPrice; }

    TicketType ticketType() const { return _ticketType; }
    void setTicketType(const TicketType &ticketType) { _ticketType = ticketType; }

    TicketClassType ticketClassType() const { return _ticketClassType; }
    void setTicketClassType(const TicketClassType &ticketClassType) { _ticketClassType = ticketClassType; }

    friend std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs);
    

    
};

#endif // TRAINTICKET_H

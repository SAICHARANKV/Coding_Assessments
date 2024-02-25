#include "TrainTicket.h"
#include<iostream>

TrainTicket::TrainTicket(float ticketPrice, TicketType ticketType,
 TicketClassType ticketClassType)
 :_ticketPrice(ticketPrice),_ticketType(ticketType),_ticketClassType(ticketClassType)
{
}
std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs) {
    os << "_ticketPrice: " << rhs._ticketPrice<<"\n";

       if(rhs._ticketType==TicketType::RESERVED)
       {
            std::cout<<"TicketType::RESERVED"<<"\n";
       }
       else if(rhs._ticketType==TicketType::WAITING)
       {
            std::cout<<"TicketType::WAITING"<<"\n";
       }
       else if(rhs._ticketType==TicketType::GENERAL)
       {
            std::cout<<"TicketType::GENERAL"<<"\n";
       }
       

       if(rhs._ticketClassType==TicketClassType::FIRST)
       {
            std::cout<<"TicketClassType::RESERVED"<<"\n";
       }
       else if(rhs._ticketClassType==TicketClassType::SECOND)
       {
            std::cout<<"TicketClassType::SECOND"<<"\n";
       }
       else if(rhs._ticketClassType==TicketClassType::AC)
       {
            std::cout<<"TicketClassType::AC"<<"\n";
       }
       else if(rhs._ticketClassType==TicketClassType::SLEEPER)
       {
            std::cout<<"TicketClassType::SLEEPER"<<"\n";
       }


    return os;
}

#include "Train.h"
#include<iostream>
#include"CriteriaNotException.h"
Train::Train(const std::string trainNumber, std::string trainStartingStation,
 std::string trainDestinationStation, int trainDepartureHour, int trainDepartureMinute,
  std::vector<TrainTicket> vectorTrainTicket)
  :_trainNumber(trainNumber),_trainStartingStation(trainStartingStation),
  _trainDestinationStation(trainDestinationStation),_vectorTrainTicket(vectorTrainTicket)
{
   
        _trainDepartureHour=trainDepartureHour;
    
    
        _trainDepartureMinute=trainDepartureMinute;
    
}
std::ostream &operator<<(std::ostream &os, const Train &rhs) {
    os << "_trainNumber: " << rhs._trainNumber<<"\n"
       << " _trainStartingStation: " << rhs._trainStartingStation<<"\n"
       << " _trainDestinationStation: " << rhs._trainDestinationStation<<"\n"
       << " _trainDepartureHour: " << rhs._trainDepartureHour<<"\n"
       << " _trainDepartureMinute: " << rhs._trainDepartureMinute<<"\n";

       for(TrainTicket trainTicket:rhs._vectorTrainTicket)
       {
            std::cout<<trainTicket<<" ";
       }


    return os;
}

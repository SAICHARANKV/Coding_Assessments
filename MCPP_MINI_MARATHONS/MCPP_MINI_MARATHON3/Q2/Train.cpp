#include "Train.hpp"
#include "TrainTicket.hpp"

Train::Train(std::string tnum, std::string start, std::string end, int deptHour, int deptMin)
    : _trainNumber(tnum), _trainStartingStation(start), _trainDestinationStation(end), _trainDepartureHour(deptHour), _trainDepartureMinute(deptMin)
{
}

std::ostream &operator<<(std::ostream &os, const Train &rhs)
{
  os << "_trainNumber: " << rhs._trainNumber
     << " _trainStartingStation: " << rhs._trainStartingStation
     << " _trainDestinationStation: " << rhs._trainDestinationStation
     << " _trainDepartureHour: " << rhs._trainDepartureHour
     << " _trainDepartureMinute: " << rhs._trainDepartureMinute
     << " \n_trainBookedTickets: [";

  for (const auto &ticket : rhs._trainBookedTickets)
  {
    os << *ticket << ", ";
  }

  os << "]";

  return os;
}

Train::Train(std::string tnum, std::string start, std::string end, int deptHour, int deptMin, std::vector<TTPointer> trainBookedTickets)
    : Train(tnum, start, end, deptHour, deptMin)
{
  _trainBookedTickets = trainBookedTickets;
}

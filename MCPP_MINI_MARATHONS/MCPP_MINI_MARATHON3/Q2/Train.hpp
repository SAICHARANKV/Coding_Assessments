#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "TrainTicket.hpp"

using TTPointer = std::shared_ptr<TrainTicket>;
class Train
{
private:
  std::string _trainNumber{"1"};
  std::string _trainStartingStation{"PUNE"};
  std::string _trainDestinationStation{"DS"};
  int _trainDepartureHour{0};
  int _trainDepartureMinute{23};
  std::vector<TTPointer> _trainBookedTickets;

public:
  /* Special Enablers and disablers */
  Train() = delete;
  Train(const Train &) = delete;
  Train(Train &&) = delete;
  Train &operator=(const Train &) = delete;
  Train &operator=(Train &&) = delete;
  ~Train() = default;

  /* Getter and Setters */
  std::string trainNumber() const { return _trainNumber; }
  void setTrainNumber(const std::string &trainNumber) { _trainNumber = trainNumber; }

  std::string trainStartingStation() const { return _trainStartingStation; }
  void setTrainStartingStation(const std::string &trainStartingStation) { _trainStartingStation = trainStartingStation; }

  std::string trainDestinationStation() const { return _trainDestinationStation; }
  void setTrainDestinationStation(const std::string &trainDestinationStation) { _trainDestinationStation = trainDestinationStation; }

  int trainDepartureHour() const { return _trainDepartureHour; }
  void setTrainDepartureHour(int trainDepartureHour) { _trainDepartureHour = trainDepartureHour; }

  int trainDepartureMinute() const { return _trainDepartureMinute; }
  void setTrainDepartureMinute(int trainDepartureMinute) { _trainDepartureMinute = trainDepartureMinute; }

  

  /* Parameterized Constructor */
  Train(std::string tnum, std::string start, std::string end, int deptHour, int deptMin, std::vector<TTPointer> trainBookedTickets);
  Train(std::string tnum, std::string start, std::string end, int deptHour, int deptMin);

  std::vector<TTPointer> trainBookedTickets() const { return _trainBookedTickets; }
  void setTrainBookedTickets(const std::vector<TTPointer> &trainBookedTickets) { _trainBookedTickets = trainBookedTickets; }

  friend std::ostream &operator<<(std::ostream &os, const Train &rhs);
};

#endif // TRAIN_HPP

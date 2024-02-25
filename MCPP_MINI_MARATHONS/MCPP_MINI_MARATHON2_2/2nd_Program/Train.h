#ifndef TRAIN_H
#define TRAIN_H

#include"TrainTicket.h"
#include<string>
#include<vector>
#include <ostream>
class Train
{
    private:
        const std::string _trainNumber;
        std::string _trainStartingStation;
        std::string _trainDestinationStation;
        int _trainDepartureHour;
        int _trainDepartureMinute;
        std::vector<TrainTicket> _vectorTrainTicket;

    public:
        Train()=default;
        Train(const Train&)=default;
        Train(Train&&)=delete;
        Train& operator=(const Train&)=delete;
        Train& operator=(Train&&)=delete;
        ~Train()=default;

        Train(const std::string trainNumber,std::string trainStartingStation,
        std::string trainDestinationStation,
        int trainDepartureHour,
        int trainDepartureMinute,
        std::vector<TrainTicket> vectorTrainTicket);

        std::string trainNumber() const { return _trainNumber; }

        std::string trainStartingStation() const { return _trainStartingStation; }
        void setTrainStartingStation(const std::string &trainStartingStation) { _trainStartingStation = trainStartingStation; }

        std::string trainDestinationStation() const { return _trainDestinationStation; }
        void setTrainDestinationStation(const std::string &trainDestinationStation) { _trainDestinationStation = trainDestinationStation; }

        int trainDepartureHour() const { return _trainDepartureHour; }
        void setTrainDepartureHour(int trainDepartureHour) { _trainDepartureHour = trainDepartureHour; }

        int trainDepartureMinute() const { return _trainDepartureMinute; }
        void setTrainDepartureMinute(int trainDepartureMinute) { _trainDepartureMinute = trainDepartureMinute; }

        std::vector<TrainTicket> vectorTrainTicket() const { return _vectorTrainTicket; }
        void setVectorTrainTicket(const std::vector<TrainTicket> &vectorTrainTicket) { _vectorTrainTicket = vectorTrainTicket; }


        friend std::ostream &operator<<(std::ostream &os, const Train &rhs);




};

#endif // TRAIN_H

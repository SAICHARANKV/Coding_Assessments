#include<iostream>
#include"Functionalities.h"
#include"EmptyContainerException.h"
#include"CriteriaNotException.h"

int main()
{   

    std::vector<TrainTicket> vectorTrainTicket;
    std::vector<std::shared_ptr<Train>> vectorTrainPointer;

    try
    {
        CreateObjects(vectorTrainTicket,vectorTrainPointer);
    }
    catch(CriteriaNotException e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout<<"---------------------------------------------------";
    std::cout<<"\n";

    try
    {
        std::optional<int> result=CountOfTrainInstances(vectorTrainPointer);
        if(result.has_value())
        {
            std::cout<<"CountOfTrainInstances:"<<result.value();
        }
    }
    catch(EmptyContainerException e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout<<"---------------------------------------------------";
    std::cout<<"\n";
    std::cout<<"ReturnTrainInstancesDepartureWithin3"<<"\n";

     try
    {
        std::optional<std::vector<Train>> result1=ReturnTrainInstancesDepartureWithin3(vectorTrainPointer,40);
        if(result1.has_value())
        {
            for(Train train:result1.value())
            {
                std::cout<<train;
            }
        }
    }
    catch(EmptyContainerException e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout<<"---------------------------------------------------";
    std::cout<<"\n";

    try
    {
        std::optional<int> result2=ReturnTotalPriceByTrainNumber(vectorTrainPointer,"100");
        if(result2.has_value())
        {
            std::cout<<"ReturnTotalPriceByTrainNumber"<<result2.value();
        }
    }
    catch(EmptyContainerException e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout<<"---------------------------------------------------";
    std::cout<<"\n";

    try
    {
        std::optional<std::string> result3=FindTrainStartingStationWithConditions(vectorTrainPointer);
        if(result3.has_value())
        {
            std::cout<<"FindTrainStartingStationWithConditions"<<result3.value();
        }
        else
        {
            std::cout<<"FindTrainStartingStationWithConditions"<<"Not Found"<<"\n";
        }
    }
    catch(EmptyContainerException e)
    {
        std::cout << e.what() << '\n';
    }
    




    return 0;
}
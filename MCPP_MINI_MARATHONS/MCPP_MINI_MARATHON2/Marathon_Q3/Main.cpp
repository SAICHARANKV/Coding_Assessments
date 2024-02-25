#include"Functionalities.h"
#include<list>

int main()
{
    FlightConatiner flightData;
    PlaneConatiner planeData;

    CreateObjects(flightData,planeData);

    FnType FindTypeOfPlane=[](const FlightConatiner& data)->void {
        if(data.empty())
        {
            throw EmptyContainerException("Data container is empty!!");
        }
        
        std::cout<<"Type of palne:";
        switch(data[0]->plane().get()->planeType())
        {
            case PlaneType::NEO:std::cout<<"NEO";
            break;
            case PlaneType::JUMBO:std::cout<<"JUMBO";
            break;
            case PlaneType::LUXURY:std::cout<<"LUXURY";
            break;
        }
        std::cout<<"\n";

    };

    FnType FindAverageCapacity=[](const FlightConatiner& data)
    {

            if(data.empty())
            {
                throw EmptyContainerException("Data container is empty!!");
            }

            float sum=0.0f;
            for(const FlightPointer& ptr:data)
            {
                if(ptr->ticketPrice()>400)
                {
                    sum+=ptr->plane().get()->capacity();
                }
            }
            std::cout<<"Average capacity:"<<sum/data.size()<<"\n";
    };

    FnType PrintDetailsOfFlight=[](const FlightConatiner& data){

        if(data.empty())
        {
            throw EmptyContainerException("Data container is empty!!");
        }

        int lowest_duration=data[0]->durationMinutes();
        for(int i=1;i<data.size();i++)
        {
            if(data[i]->durationMinutes()<lowest_duration)
            {
                lowest_duration=data[i]->durationMinutes();
            }
        }

        for(const FlightPointer& ptr:data)
        {
            if(lowest_duration==ptr->durationMinutes())
            {
                std::cout<<"Deatils of Flight with lowest duration\n"<<*ptr<<"\n";
                break;
            }
        }

    };

    try
    {
        FindTypeOfPlane(flightData);
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"----------------------------------------------------------------------"<<"\n";
    try
    {
        FindAverageCapacity(flightData);
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"----------------------------------------------------------------------"<<"\n";
    try
    {
        PrintDetailsOfFlight(flightData);
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"----------------------------------------------------------------------"<<"\n";



//Operation
    FnContainer fns{FindTypeOfPlane,FindAverageCapacity,PrintDetailsOfFlight};
    try
    {
        Operation(flightData,fns);
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    catch(FunctionConatinerException& f)
    {
        std::cout<<f.what()<<"\n";
    }
    std::cout<<"----------------------------------------------------------------------"<<"\n";

//Binded Operation
    auto Operation_binded=std::bind(Operation,std::placeholders::_2,std::placeholders::_1);
    Operation_binded(fns,flightData);
    std::cout<<"----------------------------------------------------------------------"<<"\n";

//storing functions in list
    std::list<FnType> functionList{FindTypeOfPlane,FindAverageCapacity,PrintDetailsOfFlight};

    return 0;

}
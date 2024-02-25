#include<iostream>
#include"Functionalities.h"
int main()
{


    std::array<std::thread,4> arrThreads;
    std::vector<std::function<void(std::array<int, 5>)>> functions;
    MakeLambda(functions);

    std::array<int,5> data{1,2,3,4,5};
    MappingThreads(functions,arrThreads,data);
    JoinOfThreads(arrThreads);

    std::promise<int> pr;
    std::future<int> ft=pr.get_future();

    std::future<std::array<int, 5>> res=std::async(std::launch::async,GenerateFiveIntegers,std::ref(ft));
    int N;
    std::cout<<"Enter N value";
    std::cin>>N;
    pr.set_value(N);
    std::array<int,5> result=res.get();
    for(int& ele:result)
    {
        std::cout<<"GenerateFiveIntegers"<<ele<<"\n";
    }
    return 0;
}
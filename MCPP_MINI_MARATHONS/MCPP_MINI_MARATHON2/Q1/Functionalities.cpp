#include "Functionalities.hpp"
#include "EmptyContainerException.hpp"
#include "NoInstanceFoundException.hpp"
#include "DataSizeException.hpp"
#include <cstring>
#include <string>

/* Making of Lambda Function and pushing into container */
void MakeLambdas(DataContainer &data, FnContainer &fns)
{

    /* Returning String with LeastElement size */
    auto function1 = [](std::vector<std::string> &data) -> std::string
    {
        if (data.empty())
        {
            throw EmptyContainerException("Empty Data!!!\n");
        }
        std::string LeastElement = data[0];
        for (std::string val : data)
        {
            if (LeastElement.length() > val.length())
            {
                LeastElement = val;
            }
            if (LeastElement.length() == val.length())
            {
                continue;
            }
        }
        return LeastElement;
    };

    /* Returning string with no vowels*/
    auto function2 = [](std::vector<std::string> &data) -> std::string
    {
        if (data.empty())
        {
            throw EmptyContainerException("Empty Data!!!\n");
        }
        std::string Element{""};
        int flag = 1;
        for (std::string &val : data)
        {
            int count = 0;
            for (char &ele : val)
            {
                if (ele >= 65 && ele <= 90)
                {
                    ele += 32;
                }
                if (ele == 'a' || ele == 'e' || ele == 'i' || ele == 'o' || ele == 'u')
                {
                    count++;
                }
            }
            if (count == 0)
            {
                Element = val;
                break;
            }
        }
        if (Element.length() == 0)
        {
            throw NoInstanceFoundException("No String Found Without Vowels!!!\n");
        }
        return Element;
    };

    /* Returning 2nd Element Lambda function*/
    auto function3 = [](std::vector<std::string> &data) -> std::string
    {
        if (data.empty())
        {
            throw EmptyContainerException("Empty Data!!!\n");
        }
        if (data.size() == 1)
        {
            throw DataSizeException("Data Size is one cannot find second element!!!\n");
        }
        auto itr = data.begin() + 1;

        return *itr;
    };

    /* Pushing data into container */
    fns.emplace_back(function1);
    fns.emplace_back(function2);
    fns.emplace_back(function3);
}

void PerformOperation(DataContainer &data, FnContainer &fns)
{
    if (data.empty())
    {
        throw EmptyContainerException("Empty Data!!!\n");
    }
    for (auto fn : fns)
    {
        std::cout << "Output: " << fn(data) << "\n";
    }
}
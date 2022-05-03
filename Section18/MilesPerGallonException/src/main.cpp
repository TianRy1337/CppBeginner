//Section 18 Miles per Gallon - Exception hadling
#include <iostream>
int main()
{
    int miles{};
    int gallons{};
    double milesPerGallon{};

    std::cout << "Enter miles:";
    std::cin >> miles;
    std::cout << "Enter gallons:";
    std::cin >> gallons;

    try
    {
        if(gallons == 0)
            throw 0;
        milesPerGallon = static_cast<double>(miles) / gallons;
        std::cout <<"Result : " << milesPerGallon <<std::endl;
    }
    catch(int &e)
    {
        std::cout <<"Can't divide by zero" <<std::endl;
    }
    
    
}
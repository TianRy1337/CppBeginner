//Section 18 Miles per Gallon - Exception hadling Function
#include <iostream>

double CalculateMPG(int miles, int gallons)
{
    if(gallons == 0)
        throw 0;
    return static_cast<double>(miles)/gallons;
}

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
        milesPerGallon = CalculateMPG(miles,gallons);
        std::cout <<"Result : " << milesPerGallon <<std::endl;
    }
    catch(int &e)
    {
        std::cout <<"Can't divide by zero"<<std::endl;
    }
}
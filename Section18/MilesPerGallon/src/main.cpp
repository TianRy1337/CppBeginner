//Section 18 Miles per Gallon - No Exception hadling
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

    //milesPerGallon = miles / gallons;
    if(gallons != 0)
    {
        milesPerGallon = static_cast<double>(miles) / gallons;
        std::cout <<"Result : " << milesPerGallon <<std::endl;
    }
    else
    {
        std::cerr << "Can't divide by zero" <<std::endl;
    }
    
}
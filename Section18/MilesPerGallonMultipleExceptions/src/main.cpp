//Section 18 Miles per Gallon - Function Multiple Exceptions
#include <iostream>

double CalculateMPG(int miles, int gallons)
{
    if(gallons == 0)
        throw 0;
    if(gallons < 0 || miles < 0)
        throw std::string{"Negative value error"};
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
        std::cerr <<"Can't divide by zero"<<std::endl;
    }
    catch(std::string &e)
    {
        std::cerr << e <<std::endl;
    }
}
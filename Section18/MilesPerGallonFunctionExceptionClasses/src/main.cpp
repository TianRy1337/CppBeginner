//Section 18 Miles per Gallon - User Defined Exceptions classes
#include <iostream>

class DivideByZeroException
{

};

class NegativeValueException
{

};

double CalculateMPG(int miles, int gallons)
{
    if(gallons == 0)
        throw DivideByZeroException{};
    if(gallons < 0 || miles < 0)
        throw NegativeValueException{};
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
    catch(const DivideByZeroException &e)
    {
        std::cerr <<"Can't divide by zero"<<std::endl;
    }
    catch(const NegativeValueException &e)
    {
        std::cerr << " one of parameters is Nagative" <<std::endl;
    }
}
//Section 19 Stream manipulators - Field width , justification and setfill
// setw, left, right, setfill
#include <iostream>
#include <iomanip>

int main()
{
    int num1 {1234};
    double num2{1234.5678};
    std::string hello{"Hello"};

    //default
    std::cout <<"\n == Defaults ====================" << std::endl;
    std::cout << num1 << num2 << hello << std::endl;

    //default one per line
    std::cout << num1 <<std::endl;
    std::cout << num2 <<std::endl;
    std::cout << hello <<std::endl;

    //set field width to 10, that the default justification is right for num1 only
    std::cout <<"\n == n--width 10 for num1 ====================" << std::endl;
    std::cout << std::setw(10) << num1 << num2 << hello << std::endl;

    //set field width to 10 for the first 2 outputs
    std::cout <<"\n == n--width 10 for num1 and num2 ====================" << std::endl;
    std::cout << std::setw(10) << num1 << std::setw(10) << num2 << hello << std::endl;
    
    //set field width to 10 for all 3 outputs
    std::cout <<"\n == n--width 10 for all ====================" << std::endl;
    std::cout << std::setw(10) << num1 << std::setw(10) << num2 << std::setw(10) << hello << std::endl;
    
    // setfill to '-'
    // this is persistent then repeat the previos display
    std::cout <<"\n == n--width 10 for all and left for all setfill to '-' ====================" << std::endl;
    std::cout << std::setfill('-') << std::left;
    std::cout << std::setw(10) << num1 << std::setw(10) << num2 << std::setw(10) << hello << std::endl;

    //Set width to 10 for all, left justify all and setfill character
    std::cout << std::left;
    std::cout << std::setw(10) << std::setfill('-')  << num1 << std::setw(10) << std::setfill('#')  << num2 << std::setw(10) << std::setfill('*')  << hello << std::endl;
    return 0 ;
}
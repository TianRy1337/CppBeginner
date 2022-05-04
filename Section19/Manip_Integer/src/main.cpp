//Section 19 Stream manupulators - Integer manipulators
// dec, hex, oct, showbase, uppercase, nouppercase, showpos
#include <iostream>
#include <iomanip>

int main()
{
    int num{255};

    // Displaying different bases
    std::cout << "\n ===================" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Displaying showing the base prefix for hex and oct
    std::cout << "\n ===================" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Displaying hex value in uppercase
    std::cout << "\n ===================" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // Display the + sign in front of number
    std::cout << "\n ===================" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    //setting use the set method
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    // reset to default
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);
    
    
    // input
    std::cout << "\n ===================" << std::endl;
    std::cout << "Enter an integer : ";
    std::cin >> num ;

    std::cout << "Decimal default : " << num << std::endl;
    std::cout << "Hexadecimal : " << std::hex << num << std::endl;
    std::cout << "Hexadecimal : " << std::hex << std::uppercase << num << std::endl;
    std::cout << "Hexadecimal : " << std::hex << num << std::endl;
    std::cout << "Hexadecimal : " << std::hex << std::nouppercase << num << std::endl;
    
    std::cout << "Octal : " << std::oct << num << std::endl;
    std::cout << "Hexadecimal : " << std::hex << std::showbase << num << std::endl;
    std::cout << "Octal : " << std::oct << num << std::endl;
    
    return 0;
}
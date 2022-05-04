//Section 19 Stream manipulators - Boolean boolalpha and noboolalpha
#include <iostream>
#include <iomanip>  //include this for manipullators

int main()
{
    // Default
    std::cout <<"noboolalpha => default (10==10): " <<(10==10)<<std::endl;
    std::cout <<"noboolalpha => default (10==10): " <<(10==20)<<std::endl;

    // Set to true/false formatting
    std::cout << std::boolalpha;
    std::cout <<"boolalpha => (10==10): " <<(10==10)<<std::endl;
    std::cout <<"boolalpha => (10==10): " <<(10==20)<<std::endl;

    // setting still stays for future boolean insertions
    std::cout <<"boolalpha => (10==10): " <<(10==10)<<std::endl;
    std::cout <<"boolalpha => (10==10): " <<(10==20)<<std::endl;

    // Toggle to 0/1
    std::cout << std::noboolalpha;
    std::cout <<"noboolalpha => (10==10): " <<(10==10)<<std::endl;
    std::cout <<"noboolalpha => (10==10): " <<(10==20)<<std::endl;

    // set back to true/false using setf method
    std::cout.setf(std::ios::boolalpha);
    std::cout <<"boolalpha => (10==10): " <<(10==10)<<std::endl;
    std::cout <<"boolalpha => (10==10): " <<(10==20)<<std::endl;


    // reset to default which is 0/1
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout <<"default => (10==10): " <<(10==10)<<std::endl;
    std::cout <<"default => (10==10): " <<(10==20)<<std::endl;

    return 0;
}

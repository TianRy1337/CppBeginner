//Section 19 Read File Test for file open and simple read of 3 data items
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_File;
    in_File.open("test.txt");

    std::string line;
    int num{};
    double total{};

    if(!in_File)
    {
        std::cerr << "Can't not open file"<<std::endl;
        return 1;
    }

    in_File >> line >> num >> total;

    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;

    in_File.close();

    return 0;
}
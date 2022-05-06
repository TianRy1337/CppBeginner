//Section 19 Read File 3 Read and display Poen using getline
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_File;
    in_File.open("poem.txt");
    if(!in_File)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::string line{};

    while(std::getline(in_File,line))
    {
        std::cout << line <<std::endl;
    }

    in_File.close();
    return 0;
}
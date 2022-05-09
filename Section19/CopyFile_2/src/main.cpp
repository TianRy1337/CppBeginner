//Section 19 Copy File 2 File copy using get / put
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inFile{"poem.txt"};
    std::ofstream outFile{"../src/Output.txt",std::ios::app};
    
    if(!inFile)
    {
        std::cerr << "Error opening input File" <<std::endl;
        return 1;
    }

    if(!outFile)
    {
        std::cerr << "Error opening output File" <<std::endl;
        return 1;
    }

    char c{};

    while(inFile.get(c))
    {
        outFile.put(c);
    }

    std::cout << "File copy!" << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}
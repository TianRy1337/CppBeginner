// Section 19 Challenge 4 Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


int main() 
{
    std::ifstream inFile("romeoandjuliet.txt");
    std::ofstream outFile("../src/output.txt");

    if(!inFile)
    {
        std::cerr << "can't open inFile" <<std::endl;
        return 1;
    }
    if(!outFile)
    {
        std::cerr << "can't open outFile" <<std::endl;
        return 1;
    }

//Solution 1
    // std::string line{};
    // int LineNum{1};
    // while(std::getline(inFile,line))
    // {
    //     outFile << LineNum <<"\t" << line <<std::endl;
    //     LineNum++;
    // }

//Solution 2
    std::string line{};
    int LineNum{1};
    while(std::getline(inFile,line))
    {
        if(line.length() > 0)
        {
            outFile <<std::setw(6)<<std::left << LineNum << line <<std::endl;
            LineNum++;    
        }
        else
        {
            outFile << line <<std::endl;
        }
        
    }


    inFile.close();
    outFile.close();

    return 0;
}


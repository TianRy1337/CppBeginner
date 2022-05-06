//Section 19 Read File 4 Read and display Poem.txt using unformatted get
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

    char c{};

    while(in_File.get(c))
    {
        std::cout << c;
    }
    
    in_File.close();
    return 0;
}
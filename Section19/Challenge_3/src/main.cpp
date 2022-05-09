// Section 19 Challenge 3 Word counter

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

bool FindSubstring(const string iSearchString,const string iTarget)
{
    size_t found = iTarget.find(iSearchString);
    if(found == string::npos)
        return false;
    else
        return true;
}

int main() {
    ifstream in_File;
    in_File.open("romeoandjuliet.txt");
    if(!in_File)
    {
        cerr << "Can't open File"<<endl;
        return 1;
    }

    string searchString{};
    string foundString{};
    int totalSearchStringNum{};
    int foundStringNum{};
    
    cout << "Enter the substring to search for:";
    cin >> searchString;
    
    while(in_File >> foundString)
    {
        totalSearchStringNum++;
        if (FindSubstring(searchString,foundString))
            foundStringNum++;
    }

    cout << "total Found string num : " << totalSearchStringNum << endl;
    cout << "The string " << searchString <<" has been found: " << foundStringNum  << endl;


    
    cout << endl;
    return 0;
}


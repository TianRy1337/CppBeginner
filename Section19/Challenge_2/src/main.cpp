// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ifstream in_File;
    in_File.open("responses.txt");    
    
    if(!in_File)
    {
        cerr << "Can't open in_File" <<endl;
        return 1;    
    }

    string S_CurrentAnswer{};
    string studentName{};
    string studentAnswer{};
    int totalstudent{};
    int totalScore{};
    
    double AvgScore{};
    
    getline(in_File,S_CurrentAnswer);

    cout <<setw(10)<<"Student" <<setw(10) <<"Score" <<endl;
    cout <<"===================="<<endl;
    while(getline(in_File,studentName))
    {
        totalstudent++;
        int point{0};
        getline(in_File,studentAnswer);
        for(int i = 0; i < 5; i++)
        {
            if(studentAnswer.at(i)==S_CurrentAnswer.at(i))
                point++;
        }
        totalScore+=point;
        cout <<right<<setw(10)<<studentName <<right<<setw(10) <<point <<endl;
    }
    AvgScore = (double)totalScore / (double)totalstudent;
    cout <<"Avg Score : "<<AvgScore;
    in_File.close();
    return 0;
}


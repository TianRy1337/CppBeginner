//According Beginning C++ Programming
//Section 14(164)  Overloading the Stream Insertion and Extraction Operators
#include<iostream>
#include"Mystring.h"

using namespace std;
int main()
{
    Mystring Larry{"Larry"};
    Mystring Moe{"Moe"};
    Mystring Curly;

    cout << "Enter the third stooge's first name";
    cin >> Curly;

    cout << "The three stooges are " << Larry << "," << Moe <<", and "<< Curly <<endl;

    cout << "\nEnter the three stooges names separated by a space";
    cin >> Larry >> Moe >> Curly;

    cout << "the three stooges are " << Larry << "," << Moe <<", and "<< Curly <<endl;

}
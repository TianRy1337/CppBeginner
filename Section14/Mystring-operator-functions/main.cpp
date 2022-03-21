//According Beginning C++ Programming
//Section 14(163)  Overloading Operators as Global Functions
#include <iostream>
#include <vector>
#include "Mystring.h"
using namespace std;

int main ()
{
    Mystring Larry{"Larry"};
    Mystring Moe{"Moe"};

    Mystring stooge = Larry;
    Larry.display();
    Moe.display();
    cout<<boolalpha<<endl;
    cout << (Larry == Moe) << endl;
    cout << (Larry == stooge) << endl;
    Larry.display();
    Mystring Larry2 = -Larry;
    Larry2.display();

    //Mystring stooges = Larry + "Moe";
    Mystring stooges = "Larry" + Moe + "Ryan";
    
    stooges.display();

    return 0;
}
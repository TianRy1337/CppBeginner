//According Beginning C++ Programming
//Section 14(161)  Overlaoding the Assignment Operator(move)
#include <iostream>
#include <vector>
#include "Mystring.h"
using namespace std;

int main ()
{
    cout << boolalpha << endl;

    Mystring Larry{"Larry"};
    Mystring Moe{"Moe"};

    Mystring stooge = Larry;
    Larry.display();
    Moe.display();

    cout << (Larry == Moe) << endl;
    cout << (Larry == stooge) << endl;

    Larry.display();
    Mystring Larry2 = -Larry;
    Larry2.display();

    Mystring stooges = Larry + "Moe";
    //Mystring stooges = "Larry" + Moe;

    Mystring two_stooges = Moe +" " +"Larry";
    two_stooges.display();

    Mystring three_stooges = Moe + " " + Larry + "Curly";
    three_stooges.display();

    return 0;
}
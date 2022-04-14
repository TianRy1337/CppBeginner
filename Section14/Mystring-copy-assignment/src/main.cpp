#include <iostream>
#include <vector>
#include "Mystring.h"
using namespace std;

int main ()
{
    Mystring a {"hello"};
    Mystring b;
    b = a ;
    b = "this is a test";

    Mystring empty;
    Mystring Larry("Larry");
    Mystring Stooge{Larry};
    Mystring Stooges;

    empty = Stooge;

    empty.display();
    Larry.display();
    Stooge.display();
    empty.display();

    Stooges = "Larry,Moe,and Curly";
    Stooges.display();

    vector<Mystring>Stooges_vec;
    Stooges_vec.push_back("Larry");
    Stooges_vec.push_back("Moe");
    Stooges_vec.push_back("Curly");

    cout<<"===Loop 1 ============"<<endl;
    for(const Mystring &s:Stooges_vec)
    {
        s.display();
    }

    cout<<"===Loop 2 ============"<<endl;
    for(Mystring &s:Stooges_vec)
    {
        s = "Changed"; //copy assignment   
    }

    cout<<"===Loop 3 ============"<<endl;
    for(const Mystring &s:Stooges_vec)
    {
        s.display();
    }
}
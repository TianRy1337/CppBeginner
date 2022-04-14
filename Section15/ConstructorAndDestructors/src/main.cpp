#include<iostream>
using namespace std;

class Base 
{

private:
    int value;
public:
    Base():value{0}{cout << "Base no-args constructor"<<endl;}
    Base(int x):value{x}{cout << "Base (int) constructor"<<endl;}
    ~Base(){cout << "Base destructor"<<endl;}

};

class Derived:public Base
{
    using Base::Base;//允許使用父類的建構，但可能會造成 Initializing 上的問題
private:
    int doubleValue;
public:
    Derived():doubleValue{0}{cout << "Derived no-args constructor" << endl;}
    Derived(int x):doubleValue{x*2}{cout << "Derived (int) constructor" << endl;}
    ~Derived(){cout << "Derived destructor" << endl;}
};

int main()
{
    Base b;
    Base B(123);
    Derived d;
    Derived D(10);
    return 0;
}
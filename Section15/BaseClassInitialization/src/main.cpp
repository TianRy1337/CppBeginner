#include <iostream>
using namespace std;

class Base
{
private:
    int value;
public:
    Base():value{0}
    {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x):value{x}
    {
        cout << "Base (int) overloaded constructor" << endl;
    }
    ~Base()
    {
        cout << "Base destructor" <<endl;
    }
};

class Derived:public Base
{
private:
    int doubleValue;
public:
    Derived():Base{},doubleValue{0}
    {
        cout << "Derived no-args constructor " <<endl;
    }
    Derived(int x):Base{x},doubleValue{x*2}
    {
        cout << "Derived (int) constructor " <<endl;
    }
    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};

int main()
{
    Derived d;
    Derived D{100};
    return 0;
}
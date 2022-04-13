#include <iostream>
using namespace std;
class Base
{

public:
    int a{0};
    void display(){std::cout<<a<<","<<b<<","<<c<<endl;}
protected:
    int b{0};
private:
    int c{0};

};

class Derived:public Base
{
    
public:
    void accessBaseMembers()
    {
        a = 100; // OK
        b = 200; // OK
        //c = 300; // Complier error
    }

};

int main()
{
    cout<<"=== Base member access from base objects ====" <<endl;
    Base base;
    // base.a = 100; // OK
    // base.b = 200; // Compiler error
    // base.c = 300; // Compiler error
    cout <<"=== Base member access from derived objects =====" << endl;
    Derived d;
    d.a = 100; // OK
    // d.b = 200; // Compiler error
    // d.c = 300; // Compiler error
    return 0;
}
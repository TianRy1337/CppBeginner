// Section 16 The problem
#include <iostream>
#include <memory>

class Base
{
public:
    void SayHello() const
    {
        std::cout << "Hello I'm a Base class object" << std::endl;
    }
};

class Derived:public Base
{
public:
    void SayHello() const
    {
        std::cout << "Hello - I;m a Derived class object" << std::endl;
    }

};

void Greeting(const Base &obj)
{
    std::cout << "Greeting: ";
    obj.SayHello();
}

int main()
{
    Base b ;
    b.SayHello();

    Derived d;
    d.SayHello();

    Greeting(b);
    Greeting(d);   // Shoud be Derived call SayHello()

    Base *Bptr = new Derived();
    Bptr->SayHello(); // Shoud be Derived call SayHello()

    std::unique_ptr<Base> ptr = std::make_unique<Derived>();
    ptr->SayHello(); // Shoud be Derived call SayHello()

    delete Bptr;
    return 0;
}
//Section 17 Weak Pointers
#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration
class A
{
    std::shared_ptr<B> Bptr;
public:
    void setB(std::shared_ptr<B> &b)
    {
        Bptr = b;
    }
    A(){cout << "A constructor" << endl;}
    ~A(){cout << "A destructor" << endl;}
};

class B
{
    std::weak_ptr<A> Aptr;    //make weak
public:
    void setA(std::shared_ptr<A> &a)
    {
        Aptr = a;
    }
    B(){cout << "B constructor" << endl;}
    ~B(){cout << "B destructor" << endl;}
};

int main()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->setB(b);
    b->setA(a);

    return 0;
}
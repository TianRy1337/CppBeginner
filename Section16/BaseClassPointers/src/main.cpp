//Section 16 Base Class Pointers
#include <iostream>
#include <vector>

class Account 
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account(){}

};

class Checking : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual ~Checking(){}

};

class Saving: public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Saving(){}

};

class Trust: public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust(){}

};

int main()
{
    std::cout << "\n === Pointers ===" << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Saving();
    Account *p3 = new Checking();
    Account *p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    std::cout <<"\n === Array ===" << std::endl;
    Account *array[] = {p1,p2,p3,p4};
    for (auto i = 0 ;i<4;i++)
    {
        array[i] -> withdraw(10000);
    }

    std::cout <<"\n === Vector ===" << std::endl;
    std::vector<Account*> accounts {p1,p2,p3,p4};
    for(auto accPtr:accounts)
    {
        accPtr->withdraw(1000);
    }


    std::cout << "\n === Clean Up ===" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}
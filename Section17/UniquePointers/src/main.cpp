//Section 17 Unique Pointers
#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "SavingsAccount.h"
class Test
{
private:
    int data;
public:
    Test():data{0}{std::cout<<"Test constructor ("<<data<<")"<<std::endl;}
    Test(int data):data{data}{std::cout << "Test Constructor (" << data << ")" << std::endl;}
    int getData()const{return data;}
    ~Test(){std::cout <<"Test Destructor (" << data << ")" << std::endl;}
};

using namespace std;

int main()
{
    // Test *t = new Test(1000);
    // delete t;

    // std::unique_ptr<Test> t1{new Test{100}};
    // std::unique_ptr<Test> t2 = std::make_unique<Test>(777);

    // std::unique_ptr<Test> t3;
    // t3 = std::move(t1);
    // if (!t1)
    // {
    //     std::cout<<"t1 is nullptr" << endl;
    // }

    std::unique_ptr<Account> A = std::make_unique<CheckingAccount>("Moe",5000);
    std::cout << *A << std::endl;
    A->deposit(500);
    std::cout << *A << std::endl;

    std::vector<std::unique_ptr<Account>> Accounts;

    Accounts.push_back(make_unique<CheckingAccount>("James",500));
    Accounts.push_back(make_unique<SavingsAccount>("Billy",1500));
    Accounts.push_back(make_unique<TrustAccount>("Bobby",5500,3));

    for(const auto &Acc : Accounts)
    {
        std::cout << *Acc <<std::endl;
    }

    return 0;
}

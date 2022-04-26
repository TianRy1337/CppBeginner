// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() 
{
    // cout.precision(2);
    // cout << fixed;
    // Checking_Account c{"ABC"};
    // c.deposit(100);
    // c.withdraw(1000);
    // cout << c <<endl;
    
    Account *p1 = new Checking_Account("JAMES");
    Account *p2 = new Savings_Account("MOE",1000);
    Account *p3 = new Trust_Account("Curly",10000);

    std::vector<Account*> accounts{p1,p2,p3};

    display(accounts);
    deposit(accounts,150);
    withdraw(accounts,100);
    
    return 0;
}


#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    // test your code here
    try 
    {
        std::unique_ptr<Account> moesAccount = std::make_unique<Checking_Account>("Moe", -110.0);
        std::cout << *moesAccount << std::endl;
        moesAccount->withdraw(500);
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}


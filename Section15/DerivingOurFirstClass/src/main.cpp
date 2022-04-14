#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
using namespace std;

int main()
{
    //Use the Account class
    cout << "\n === Account =================" <<endl;
    Account acc{};
    acc.deposit(1234.0);
    acc.withdraw(123.0);
    cout << endl;

    Account *pAcc{nullptr};
    pAcc = new Account();
    pAcc -> deposit(100.0);
    pAcc -> withdraw(59.0);
    delete pAcc;

    //Use the Savings Account class
    cout << "\n === Savings Account =================" <<endl;
    Savings_Account SavAcc{};
    SavAcc.deposit(1234.0);
    SavAcc.withdraw(123.0);
    cout << endl;

    Savings_Account *pSavingAcc {nullptr};
    pSavingAcc = new Savings_Account();
    pSavingAcc -> deposit(1234.0);
    pSavingAcc -> withdraw(123.0);
    delete pSavingAcc;

    cout << "\n ======================================" <<endl;
    return 0;
}
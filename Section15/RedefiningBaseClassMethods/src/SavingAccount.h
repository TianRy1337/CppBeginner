#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

class SavingAccount:public Account
{
    friend std::ostream &operator<< (std::ostream &os,const SavingAccount &account);
protected:
    double intRate;
public:
    SavingAccount();
    SavingAccount(double balance,double intRate);
    void deposit(double amount);
    //Withdraw is inherited
};

#endif
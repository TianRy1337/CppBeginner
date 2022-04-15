#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_
#include "Account.h"

class SavingAccount:public Account
{
    friend std::ostream &operator<< (std::ostream &os ,const SavingAccount &account);
private:
    static constexpr const char *defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;

protected:
    double intRate;
public:
    SavingAccount(std::string name = defName, double balance = defBalance,double intRate = defIntRate);
    bool deposit (double amount);
};

#endif
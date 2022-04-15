#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_
#include <string>
#include "SavingAccount.h"

class TrustAccount:public SavingAccount
{
    friend std::ostream &operator<< (std::ostream &os ,const TrustAccount &account);
private:
    static constexpr const char *defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
    static constexpr double defWithdrawTime = 0;

protected:
    double intRate;
    int withdrawTime;
public:
    TrustAccount(std::string name = defName, double balance = defBalance, double intRate = defIntRate ,int withdrawTime = defWithdrawTime);
    bool deposit(double amount);
    bool withdraw(double amount);
};


#endif
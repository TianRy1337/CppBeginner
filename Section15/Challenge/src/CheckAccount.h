#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_
#include <string>
#include "Account.h"
class CheckAccount:public Account
{
    friend std::ostream &operator<< (std::ostream &os ,const CheckAccount &account);
private:
    static constexpr const char *defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defFee = 1.5;
protected:
    double fee;
public:
    CheckAccount(std::string name = defName , double balance = defBalance,double fee = defFee);
    bool withdraw(double amount);
};

#endif
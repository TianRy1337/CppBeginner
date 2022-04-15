#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account
{
    friend std::ostream &operator<<(std::ostream &os,const Account &account);
private:
    static constexpr const char *defName = "Unnamed Account";
    static constexpr const double defBalance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = defName,double balance = defBalance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance()const;
};
#endif
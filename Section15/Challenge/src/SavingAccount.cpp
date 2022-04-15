#include "SavingAccount.h"

SavingAccount::SavingAccount(std::string name,double balance, double intRate):Account{name,balance},intRate{intRate}
{

}


bool SavingAccount::deposit(double amount)
{
    amount += amount * (intRate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os , const SavingAccount &account)
{
    os << "SavingAccount : " << account.name << " : " << account.balance << " , " <<account.intRate << "%";
    return os;
}
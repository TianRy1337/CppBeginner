#include "SavingAccount.h"

SavingAccount::SavingAccount():SavingAccount{0.0,0.0}
{

}

SavingAccount::SavingAccount(double balance, double intRate):Account(balance),intRate{intRate}
{

}


void SavingAccount::deposit(double amount)
{
    amount = amount + (amount * intRate / 100);
    Account::deposit(amount);

}

std::ostream &operator<<(std::ostream &os , const SavingAccount &account)
{
    os << "Saving Account balance : " << account.balance << " Interest rate:" << account.intRate;
    return os;
}
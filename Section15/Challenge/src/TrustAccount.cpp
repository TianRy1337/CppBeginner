#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name , double balance , double IntRate , int withdrawTime):SavingAccount{name,balance},intRate{intRate},withdrawTime{withdrawTime}
{

}


bool TrustAccount::deposit(double amount)
{

    if(amount > 5000.0)
    {
        balance += 50;
    }
    return SavingAccount::deposit(amount);
    
}

bool TrustAccount::withdraw(double amount)
{
    withdrawTime += 1;
    if(withdrawTime > 3)
    {
        std::cout << "Trust Account Fail Withdraw" << std::endl;
        return false;
    }
    else
    {
        return SavingAccount::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os , const TrustAccount &account)
{
    os << "TrustAccount : " << account.name << " : " << account.balance << " , " << "Already withdraw time : "<<account.withdrawTime;
    return os;
}

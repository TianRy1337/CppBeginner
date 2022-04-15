#include "CheckAccount.h"

CheckAccount::CheckAccount(std::string name , double balance , double fee):Account{name,balance},fee{fee}
{

}

bool CheckAccount::withdraw(double amount)
{
    amount += fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os , const CheckAccount &account)
{
    os << "CheckAccount : " << account.name << " : " << account.balance << " , " <<account.fee << "%";
    return os;
}
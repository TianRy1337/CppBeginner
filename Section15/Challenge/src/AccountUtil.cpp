#include <iostream>
#include "AccountUtil.h"

void display(const std::vector<Account> &accounts)
{
    std::cout <<"\n==== Accounts ========" << std::endl;
    for(const auto &acc:accounts)
    {
        std::cout << acc <<std::endl;
    }
}

void deposit(std::vector<Account> &accounts ,double amount)
{
    std::cout <<"\n====Depositing to  Accounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.deposit(amount))
        {
            std::cout <<"Deposited "<< amount <<" to "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Deposited of "<< amount <<" to "<< acc << std::endl;
        }
    }
}

void withdraw(std::vector<Account> &accounts ,double amount)
{
    std::cout <<"\n====Withdrawing from  Accounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.withdraw(amount))
        {
            std::cout <<"Withdrew "<< amount <<" from "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Withdrawl of "<< amount <<" from "<< acc << std::endl;
        }
    }
}

void display(const std::vector<SavingAccount> &accounts)
{
    std::cout <<"\n==== Savings Accounts ========" << std::endl;
    for(const auto &acc:accounts)
    {
        std::cout << acc <<std::endl;
    }
}

void deposit(std::vector<SavingAccount> &accounts ,double amount)
{
    std::cout <<"\n====Depositing to  Accounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.deposit(amount))
        {
            std::cout <<"Deposited "<< amount <<" to "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Deposited of "<< amount <<" to "<< acc << std::endl;
        }
    }
}

void withdraw(std::vector<SavingAccount> &accounts ,double amount)
{
    std::cout <<"\n====Withdrawing from  Accounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.withdraw(amount))
        {
            std::cout <<"Withdrew "<< amount <<" from "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Withdrawl of "<< amount <<" from "<< acc << std::endl;
        }
    }
}

void display(const std::vector<CheckAccount> &accounts)
{
    std::cout <<"\n==== CheckAccounts ========" << std::endl;
    for(const auto &acc:accounts)
    {
        std::cout << acc <<std::endl;
    }
}

void deposit(std::vector<CheckAccount> &accounts ,double amount)
{
    std::cout <<"\n====Depositing to  CheckAccounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.deposit(amount))
        {
            std::cout <<"Deposited "<< amount <<" to "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Deposited of "<< amount <<" to "<< acc << std::endl;
        }
    }
}

void withdraw(std::vector<CheckAccount> &accounts ,double amount)
{
    std::cout <<"\n====Withdrawing from  CheckAccounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.withdraw(amount))
        {
            std::cout <<"Withdrew "<< amount <<" from "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Withdrawl of "<< amount <<" from "<< acc << std::endl;
        }
    }
}

void display(const std::vector<TrustAccount> &accounts)
{
    std::cout <<"\n==== TrustAccounts ========" << std::endl;
    for(const auto &acc:accounts)
    {
        std::cout << acc <<std::endl;
    }
}

void deposit(std::vector<TrustAccount> &accounts ,double amount)
{
    std::cout <<"\n====Depositing to  TrustAccounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.deposit(amount))
        {
            std::cout <<"Deposited "<< amount <<" to "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Deposited of "<< amount <<" to "<< acc << std::endl;
        }
    }
}

void withdraw(std::vector<TrustAccount> &accounts ,double amount)
{
    std::cout <<"\n====Withdrawing from  TrustAccounts ========" << std::endl;
    for(auto &acc:accounts)
    {
        if(acc.withdraw(amount))
        {
            std::cout <<"Withdrew "<< amount <<" from "<< acc << std::endl;
        }
        else
        {
            std::cout <<"Failed Withdrawl of "<< amount <<" from "<< acc << std::endl;
        }
    }
}
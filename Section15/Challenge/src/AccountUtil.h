#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckAccount.h"
#include "TrustAccount.h"

void display(const std::vector <Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);


void display(const std::vector <SavingAccount> &accounts);
void deposit(std::vector<SavingAccount> &accounts, double amount);
void withdraw(std::vector<SavingAccount> &accounts ,double amount);

void display(const std::vector <CheckAccount> &accounts);
void deposit(std::vector<CheckAccount> &accounts, double amount);
void withdraw(std::vector<CheckAccount> &accounts ,double amount);

void display(const std::vector <TrustAccount> &accounts);
void deposit(std::vector<TrustAccount> &accounts, double amount);
void withdraw(std::vector<TrustAccount> &accounts ,double amount);

#endif
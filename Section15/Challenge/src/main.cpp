#include <iostream>
#include <vector>
#include "SavingAccount.h"
#include "AccountUtil.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout <<fixed;

    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moem",2000});
    accounts.push_back(Account{"Curly",5000});

    display(accounts);
    deposit(accounts,1000);
    withdraw(accounts,2000);


    vector<SavingAccount> SavingAccounts;
    SavingAccounts.push_back(SavingAccount{});
    SavingAccounts.push_back(SavingAccount{"Superman"});
    SavingAccounts.push_back(SavingAccount{"Batman",2000});
    SavingAccounts.push_back(SavingAccount{"Wonderwowan",5000,5.0});

    display(SavingAccounts);
    deposit(SavingAccounts,1000);
    withdraw(SavingAccounts,2000);

    // Checking
   
    vector<CheckAccount> check_accounts;
    check_accounts.push_back(CheckAccount {} );
    check_accounts.push_back(CheckAccount {"Kirk"} );
    check_accounts.push_back(CheckAccount {"Spock", 2000} );
    check_accounts.push_back(CheckAccount {"Bones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
    vector<TrustAccount> trust_accounts;
    trust_accounts.push_back(TrustAccount {} );
    trust_accounts.push_back(TrustAccount {"Athos", 10000, 5.0} );
    trust_accounts.push_back(TrustAccount {"Porthos", 20000, 4.0} );
    trust_accounts.push_back(TrustAccount {"Aramis", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
   
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    
    return 0;
}
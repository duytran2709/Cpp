#include <iostream>
#include "BankAccount3.h"

#include <stdexcept>
using namespace std;

string BankAccountException::why() const
{
    return m_err;
}


/**********************************************************/

BankAccount::BankAccount()
{
    m_balance = 0;
}

BankAccount::BankAccount(double initialBalance)
{
    m_balance = initialBalance ;
}

bool      BankAccount::deposit(double amount)
{
	if (amount <= 0)
		throw BankAccountException(" Deposit amount must be > 0.");
	
    m_balance += amount ;
    return true;
}

bool     BankAccount::withdraw(double amount)
{
    m_balance  -= amount ;
    return true;
}

double   BankAccount::balance() const
{
    return ( m_balance ) ;
}

void     BankAccount::print() const
{
    cout << "Balance: " << m_balance << endl;
}

// Note: must call super class constructor in the initializer list
SavingAccount::SavingAccount(double initialBalance, int year, double rate) :
   BankAccount(initialBalance)
{
   // BankAccount(initialBalance);   doesn't work
   m_year_opened = year;
   m_interest_rate = rate;
}

void     SavingAccount::print() const
{
    // cout << "Balance: " << m_balance << endl;
	cout << BankAccount::m_id << endl;
	BankAccount::print();
	cout << " Year opened: " << m_year_opened << "\t interest rate: "
            	<< m_interest_rate << endl;
}



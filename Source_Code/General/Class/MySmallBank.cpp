#include <iostream>
using namespace std;
#include "BankAccount.h"

int main()
{
        cout << "Welcome to my small bank." << endl;
		BankAccount  acct ;
		acct.deposit(100);
		// cout << acct.m_balance << endl;
		acct.print();

		acct.withdraw(20);
		acct.print() ;
		
		BankAccount yourAcct(200);
		yourAcct.deposit(50);
		yourAcct.print() ;
		
		BankAccount ourAcct;
		ourAcct.deposit(acct.balance() + yourAcct.balance());
		ourAcct.print();
		
		cout << "Thank you for using my bank." << endl;
		
        return 0 ;
}


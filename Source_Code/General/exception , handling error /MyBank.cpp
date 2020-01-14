#include <iostream>
using namespace std;
#include "BankAccount3.h"

int main()
{
    cout << "Welcome to my small bank." << endl;
    BankAccount  acct(1000);
		
	try 
	{
	   //acct.deposit(-100);
	   acct.deposit(150);
	   acct.print();
    }
	catch (BankAccountException err)
	{
		cout << "From catch BankAccountException:" << endl;
		cout << err.why() << endl;
		
	}

		
    cout << "Thank you for using my bank." << endl;
		
    return 0 ;
}


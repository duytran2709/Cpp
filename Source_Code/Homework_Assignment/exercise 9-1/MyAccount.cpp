/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Exercise 9.1
 * File name: MyAccount.cpp
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/
#include "account.h" 

using namespace std;



int main()

{
    BankAccount account1("duy", 0.0), account2("hai", 0.0), account3("nam", 0.0);
    cout << " Enter account1's balance" << endl;
    account1.input();
    cout << endl;
    account1.output();
    cout << endl;

    cout << " Enter account2's balance" << endl;
    account2.input();
    cout << endl;
    account2.output();
    cout << endl;

    cout << " Enter account3's balance" << endl;
    account3.input();
    cout << endl;
    account3.output();
    cout << endl;
    return 0;
}


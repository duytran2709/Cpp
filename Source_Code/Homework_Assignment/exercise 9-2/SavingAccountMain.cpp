/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Exercise 9.2
 * Filename : SavingAccountMain.cpp
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/


#include "SavingAccount.h"

using namespace std;

int main ()

{
    
    SavingAccount account1("duy", 0.0 , 0 , 0.0), account2("hai",0.0 , 0 , 0.0), account3("nam", 0.0 , 0 , 0.0);
    cout << " Enter account1's balance" << endl;
    account1.input();
    cout << endl;
    account1.print();
    cout << endl;

    cout << " Enter account2's balance" << endl;


    account2.input();
    cout << endl;
    account2.print();
    cout << endl;

    cout << " Enter account3's balance" << endl;
    account3.input();
    cout << endl;
    account3.print();
    cout << endl;
    return 0;

}
/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Exercise 9.2
 * Filename : account.h
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream> 
#include <string>

using namespace std;

class BankAccount

{
  public:
    BankAccount(string name, double balance);

    void setName ( string name );
    string getName () ;

    void setBalance ( double balance ); 
    double getBalance ();

    void input();

    void output();
    
    bool withdraw(double amount);
    bool deposit(double amount);

    double amount1, amount2;


  private:
    string ownerName ;
    double accountBalance;
};

#endif
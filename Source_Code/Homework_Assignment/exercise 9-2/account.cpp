/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Exercise 9.2
 * File name : account.cpp
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/

#include <string>

#include "account.h"

BankAccount::BankAccount(string name, double balance) 
{
    ownerName = name;
    accountBalance = balance;
}

void BankAccount::setName ( string name )
{
    ownerName = name;
}

string BankAccount::getName()
{
    return ownerName;
}

void BankAccount::setBalance ( double balance )
{
    accountBalance = balance;
}

double BankAccount::getBalance()
{
    return accountBalance;
}

void BankAccount::input()
{

    cout << " Enter balance: ";
    cin >> accountBalance;
    cout << " Enter the amount to deposit: ";
    cin >> amount2;
    cout << " Enter the amount to withdraw: ";
    cin >> amount1;
}

void BankAccount::output()
{
    cout << " The owner name is : " << getName()  << endl;
    cout << " The deposit status: " << boolalpha << deposit(amount2) << endl;
    cout << " The withdraw status: " << boolalpha << withdraw(amount1) << endl;
    cout << " The balance is : " << getBalance() << endl;
}

bool BankAccount::withdraw(double amount)
{
    if (amount > accountBalance)
    {
        cout << " The withdraw amount is greater than the balance! ";
        return false;
    }
    else
    {
        accountBalance -= amount;
        return true;
    }
}

bool BankAccount::deposit(double amount)
{

    if (amount < 0)
    {
        cout << " Error! The amount is negative! ";
        return false;
    }
    else
    {
        accountBalance += amount;
        return true;
    }
}

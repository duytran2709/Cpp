/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Exercise 9.2
 * Filename : SAvingAccount.cpp
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/

#include <iostream>
#include <iomanip>
#include "SavingAccount.h"

using namespace std;

SavingAccount::SavingAccount(string name, double balance, int year, double rate)
    : BankAccount(name, balance)
{
    setYear(year);
    setRate(rate);
}

void SavingAccount::setYear(double year)
{
    m_year_open = year;
}

int SavingAccount::getYear()
{
    return m_year_open;
}

void SavingAccount::setRate(double rate)
{
    m_interest_rate = rate;
}

double SavingAccount::getRate()
{
    return m_interest_rate;
}

double SavingAccount::calculatedInterest()
{
    return getYear() * ((getRate() * BankAccount::getBalance()) / 100);
}

void SavingAccount::input()
{   int year ;
    double rate;
    BankAccount::input();
    cout << "Year of account: ";
    cin >> year; 
    setYear(year);
    cout << "Rate of interest: ";
    cin >> rate;
     setRate(rate);
}

void SavingAccount::print()
{
    cout << fixed << setprecision(2);
    BankAccount::output();
    cout << "Year of account: " << getYear() << endl;
    cout << "Rate of interest: " << getRate() << endl;
    cout << "Interest amount: " << calculatedInterest() << endl;
}
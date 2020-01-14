/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Exercise 9.2
 * Filename : SavingAccount.h
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/

#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <string>

#include "account.h"



using namespace std;

class SavingAccount : public BankAccount

{
    public:

    SavingAccount ( string name , double balance , int year , double rate );

    void setYear ( double );

    int getYear ();

    void setRate (double );
    
    double getRate ();

    double calculatedInterest ();

    void input();
    void print ();




    private:

    int m_year_open;
    double m_interest_rate;

};

#endif



/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Project Assignment 3
 * Filename : expense.h
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/

#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <cstdlib>
#include <fstream>

#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <stdexcept> 

using namespace std;

class Expense

{
  public:
    Expense();

    void setDescription(string description);
    string getDescription();

    void setAmount(float amount);
    float getAmount();

    void setCapacity(const int capacity);
    const int getCapacity();


    void inputData();
    void print ();
    string toLowerCase(string aCppString);
    void searchAmount ( Expense expenseArray []  , int cur ) ;
    void searchString ( Expense expenseArray[] , int cur  ) ;
    
   

  private:
    string m_description;
    float m_amount;
};

#endif
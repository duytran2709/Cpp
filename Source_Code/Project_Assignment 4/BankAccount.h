/**************************************************************
 * West Valley College - CIS 004A 
 * Project Assignment 4 
 * Student : Duy Tran 
 * Student id : G01826554
 * File name : BankAccount.h
 * Edittor : Visual Studio Code 
 * Compiler : GCC
 *************************************************************/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string> // for string
#include <cmath>
#include <cstdlib> // for atoi
#include <iomanip> // for setw
#include <algorithm>
#include <exception> // for exception
#include <stdexcept>
#include <ctime> // for getting current time

using namespace std;

/**************************************************************
 * Struct Transaction
 * Purpose : store the information of every transactions 
 * Date member : 
 * m_amount 
 * description
 * m_time 
 *************************************************************/

struct Transaction
{
  double m_amount;
  string description;
  string m_time;
};

const int CAPACITY = 100;

/**************************************************************
 * Class BankAccountException 
 * Purpose : defining and handling the errors 
 
 !!!!!!  Note : there was an error with compiler 
  when I tried to make this class to inherite from runtim_error class !!!!!!
 *************************************************************/

class BankAccountException
{
private:
  string m_err;

public:

  BankAccountException () {} ; 
  BankAccountException (string message ) : m_err (message ) {} ; 

  void setErr(string errMsg);

  string why() const;

  string checkAccount() const;

  void exitProgram();
};

/**************************************************************
 * SuperClass BankAccount
 * Purpose : initialize name, balance , 
  and keep track of all type of transaction 
 *************************************************************/

class BankAccount
{
private:
  string m_name;
  double initialBalance;
  double totalBalance;
  int m_cur_index;
  Transaction transactionArray[CAPACITY];

public:
  BankAccount();
  BankAccount(string name, double initialBalance);

  void setName(string &name);
  string getName();
  void set_initialBalance(double balance);
  double get_initialBalance();
  void setTotalBalance(double totalBalance);
  double getTotalBalance();
  Transaction getTransactionIndex(int index);
  int getCurrentIndex();

  void accountCheck(bool account_check);
  bool deposit(double amount, time_t Time);
  bool withdraw(double amount, time_t Time);
  void printAllTransactions();
};

/**************************************************************
 * SubClass SavingAccount 
 * Inherited from SupperClass BankAccount
 * Purpose : initialize the year opening account, the rate of interest ,
       and keep track of interest 
 *************************************************************/

class SavingAccount : public BankAccount
{
private:
  int m_year_opened;
  double m_interest_rate;
  double interest;

public:
  SavingAccount();
  SavingAccount(string name, double initialBalance, int year, double rate);

  void setInterest();
  double getInterest();
  void set_InterestRate(double &interest);
  double get_InterestRate();
  void setYear(int year);
  int getYear();

  void initialize(string name, double balance, int year, double rate);
  string toString();
  double calculateTotalBalance();
  double set_NewTotalBalance (); 
};

#endif

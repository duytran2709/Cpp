/**************************************************************
 * West Valley College - CIS 004A 
 * Project Assignment 4 
 * Student : Duy Tran 
 * Student id : G01826554
 * File name : BankAccount.cpp
 * Edittor : Visual Studio Code 
 * Compiler : GCC
 *************************************************************/

#include "BankAccount.h"

using namespace std;

/****************************************************************
********** BankAccountException Class's implementation of methods ******************* 
****************************************************************/

void BankAccountException::setErr(string errMsg)
{
    m_err = errMsg;
}

        /**************************************************************
         * Purpose : print out the error message 
         *************************************************************/
string BankAccountException::why() const
{
    return m_err;
}

         /**************************************************************
         * Purpose : check if there is an amount opened 
         *************************************************************/
string BankAccountException::checkAccount() const
{
    return "There is no account opened ";
}

        /**************************************************************
         * Purpose : exit the program 
         *************************************************************/

void BankAccountException::exitProgram()
{
    cout << "\n*** The program exits ***\n"
         << endl;
    exit(0);
}

/****************************************************************
********** BankAccount Class's implementation of methods ******************* 
****************************************************************/

BankAccount::BankAccount()
{
    m_name = "";
    initialBalance = 0.0;
    totalBalance = 0.0;
    m_cur_index = 0;
}

void BankAccount::setName(string &name)
{
    m_name = name;
}

string BankAccount::getName()
{
    return m_name;
}

void BankAccount::set_initialBalance(double balance)
{
    initialBalance = balance;
}

double BankAccount::get_initialBalance()
{
    return initialBalance;
}

void BankAccount::setTotalBalance(double balance)
{
    totalBalance = balance;
}

double BankAccount::getTotalBalance()
{
    return totalBalance;
}

Transaction BankAccount::getTransactionIndex(int index)
{
    return transactionArray[index];
}

int BankAccount::getCurrentIndex()
{
    return m_cur_index;
}

        /**************************************************************
         * Purpose : deposit money to the totalBalance 
         *************************************************************/
bool BankAccount::deposit(double amount, time_t Time)
{
    if (amount <= 0)
    {
        // BankAccountException err;
        // err.setErr("The deposit amount is negative ");
        throw BankAccountException ("The deposit amount is negative " ) ;
    }
    else
    {
        transactionArray[m_cur_index].description = "Deposit";
        transactionArray[m_cur_index].m_amount = amount;
        transactionArray[m_cur_index].m_time = ctime(&Time);
        totalBalance += amount;
        m_cur_index++;
        return true;
    }
}
            /**************************************************************
         * Purpose : withdraw money from totalBalance 
         *************************************************************/
bool BankAccount::withdraw(double amount, time_t Time)
{
    if (amount > totalBalance)
    {
         throw BankAccountException ("You can't withdraw the amount being greater than balance " ) ;
    }
    else
    {
        transactionArray[m_cur_index].description = "Withdraw";
        transactionArray[m_cur_index].m_amount = amount;
        transactionArray[m_cur_index].m_time = ctime(&Time);
        totalBalance -= amount;
        m_cur_index++;
        return true;
    }
}

        /**************************************************************
         * print out  all transactions including description, amount and time
         *************************************************************/
void BankAccount::printAllTransactions()
{

    for (int i = 0; i < m_cur_index; i++)
    {
        cout << transactionArray[i].description << " " << setw(10)
             << "$" << transactionArray[i].m_amount << "\t\t"
             << transactionArray[i].m_time;
    }
}

/****************************************************************
********** SavingAccount Class's implementation  of methods ******************* 
****************************************************************/

SavingAccount::SavingAccount()
{
    m_year_opened = 0;
    m_interest_rate = 0.0;
}

void SavingAccount::setInterest()
{
    interest = get_initialBalance() * (2018 - getYear()) * m_interest_rate / 100;
}

double SavingAccount::getInterest()
{
    return interest;
}

void SavingAccount::set_InterestRate(double &interest)
{
    m_interest_rate = interest;
}

double SavingAccount::get_InterestRate()
{

    return m_interest_rate;
}

void SavingAccount::setYear(int year)
{
    m_year_opened = year;
}

int SavingAccount::getYear()
{
    return m_year_opened;
}
        /**************************************************************
         * initialize the information of account from keyboard input 
         *************************************************************/

void SavingAccount::initialize(string name, double balance, int year, double rate)
{
    setName(name);
    set_initialBalance(balance);
    m_year_opened = year;
    m_interest_rate = rate;
}
        /**************************************************************
         * Purpose : print out the totalBalance 
         *************************************************************/
string SavingAccount::toString()
{
    double totalBalance = BankAccount::getTotalBalance();
    return to_string(totalBalance);
}

double SavingAccount::calculateTotalBalance()
{

    double total = interest + get_initialBalance();
    BankAccount::setTotalBalance(total);
    return total;
}

        /**************************************************************
         * Purpose : set New totalBalance after changing the interest's rate 
         *************************************************************/
 double SavingAccount::set_NewTotalBalance()
{
    double total; 
    for (int i = 0; i <= getCurrentIndex(); i++)
    {
        if (getTransactionIndex(i).description == "Deposit")
        {
             total = getTotalBalance() + getTransactionIndex(i).m_amount;
            setTotalBalance(total);
        }
        else if (getTransactionIndex(i).description == "Withdraw")
        {
            total = getTotalBalance() - getTransactionIndex(i).m_amount;
            setTotalBalance(total);
        }
    }
    return total; 
}
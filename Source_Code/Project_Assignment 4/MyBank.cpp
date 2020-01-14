/**************************************************************
 * West Valley College - CIS 004A 
 * Project Assignment 4 
 * Student : Duy Tran 
 * Student id : G01826554
 * File name : MyBank.cpp
 * Edittor : Visual Studio Code 
 * Compiler : GCC
 *************************************************************/

#include "BankAccount.h"
#include <cstdlib>
#include <string>

using namespace std;

/**************************************************************
    Declaration of the function 
*************************************************************/

void checkPassword(int counter, string password);

int main()
{
    BankAccountException err;
    SavingAccount saving;
    bool account_check = false;
    time_t Time = time(NULL);

    cout << "***** Welcome to My Bank Account *****" << endl;

    /**************************************************************
 * Check for the password which is "abc123" 
 * Method used :
 *        BankAccount::checkPassword
 *        BankAccountException::what 
 *        BankAccountException::exitProgram
 *************************************************************/

    for (int counter = 0;; counter++)
    {
        try
        {
            string password = "";
            cout << " Please input the password: ";
            getline(cin, password);
            checkPassword(counter, password);
        }
        catch (BankAccountException err)
        {
            cout << err.why() << endl;
        }
        catch (int counter)
        {
            err.exitProgram();
        }
        catch (string password)
        {
            break;
        }
    }

    while (true)
    {
        /**************************************************************
     * Menu of BankAccount
     *************************************************************/
        string buf = "";
        cout << " \n---- Menu ---- " << endl;
        cout << "1. Open an account " << endl;
        cout << "2. Deposit " << endl;
        cout << "3. Withdraw " << endl;
        cout << "4. Show balance (including principal and interest) " << endl;
        cout << "5. Show all transactions " << endl;
        cout << "6. Set interest rate " << endl;
        cout << "7. Exit " << endl;
        cout << "Please enter your option : ";
        cin >> buf;
        int menu_option = atoi(buf.c_str());

        /**************************************************************
         * Option 1: ask the user to initialize name, balance, year, interest rate of the account
         * Method used :
         *       SavingAccount::initialize
         *       SavingAccount::setInterest
         *       SavingAccount::calculateTotalBalance 
         *       BankAccountException::checkAccount
         *       BankAccountException::why 
         *************************************************************/

        if (menu_option == 1)
        {
            cout << "\n--- Option1: Open account ---\n " << endl;
            try
            {
                if (account_check == true)
                    throw account_check;
                else
                {
                    string name = "";
                    double balance = 0.0;
                    int year = 0;
                    double rate = 0.0;
                    cout << "Please enter account's name : ";
                    getline(cin, name);
                    cin.ignore(1000, 10);
                    cout << "Please enter initial balance : ";
                    cin >> balance;
                    cout << "Please enter year: ";
                    cin >> year;
                    cout << "Please enter rate of interest: ";
                    cin >> rate;
                    saving.initialize(name, balance, year, rate);
                    saving.setInterest();
                    saving.calculateTotalBalance();
                    account_check = true;
                }
            }
            catch (bool account_check)
            {
                cout << err.checkAccount() << endl;
            }
            catch (BankAccountException err)
            {
                cout << err.why();
            }
        }

        /**************************************************************
         * Option 2: ask user for depositing
         * Method used :
         *       BankAccount::deposit
         *       BankAccountException::checkAccount
         *       BankAccountException::why 
         *************************************************************/
        else if (menu_option == 2)
        {
            try
            {
                if (account_check == false)
                    throw account_check;
                else
                {
                    cout << "\n --- Option2: Deposit --- \n"
                         << endl;
                    double amount = 0.0;
                    cout << "Please enter deposit amount: ";
                    cin >> amount;
                    saving.deposit(amount, Time);
                    cout << "You deposited $" << amount << " at " << ctime(&Time) << endl;
                }
            }
            catch (BankAccountException err)
            {
                cout << err.why();
            }
            catch (bool check)
            {
                cout << err.checkAccount() << endl;
            }
        }

        /**************************************************************
         * Option 3: ask the user for withdrawal 
         * Method used :
         *       BankAccount::withdraw 
         *       BankAccountException::checkAccount
         *       BankAccountException::why 
         *************************************************************/
        else if (menu_option == 3)
        {
            try
            {
                if (account_check == false)
                    throw account_check;
                else
                {
                    cout << "\n --- Option3 : Withdraw --- \n " << endl;
                    double amount = 0.0;
                    cout << "Please enter withdraw amount: ";
                    cin >> amount;
                    saving.withdraw(amount, Time);
                    cout << "You withdrawed $" << amount << " at " << ctime(&Time) << endl;
                }
            }
            catch (BankAccountException err)
            {
                cout << err.why();
            }
            catch (bool check)
            {
                cout << err.checkAccount() << endl;
            }
        }
        /**************************************************************
         * Option 4: Show balance including the principal and interest 
         * Method used :
         *        BankAccout::get_initialBalance 
         *        SavingAccount::get_InterestRate
         *         SavingAccount::getInterest 
         *        SavingAccount::toString 
         *         BankAccountException::checkAccount
         *       BankAccountException::why 
         *************************************************************/
        else if (menu_option == 4)
        {
            try
            {
                if (account_check == false)
                    throw account_check;
                else
                {
                    cout << " --- Option4: Show balance --- " << endl;
                    cout << "Your principal : $" << saving.get_initialBalance() << endl;
                    cout << "Your interest rate : " << saving.get_InterestRate() << "%" << endl;
                    cout << "Your interest: $" << saving.getInterest() << endl;
                    cout << "Your current balance at " << ctime(&Time) << "is: "
                         << saving.toString() << endl;
                }
            }
            catch (bool check)
            {
                cout << err.checkAccount() << endl;
            }
        }

        /**************************************************************
         * Option 5: Show all transactions 
         * Method used :
         *        BankAccount::printAllTransactions
         *       BankAccountException::checkAccount
         *       BankAccountException::why 
         *************************************************************/
        else if (menu_option == 5)
        {
            try
            {
                if (account_check == false)
                    throw account_check;
                else
                {
                    cout << " --- Option5 : Show all transactions ---" << endl;
                    cout << "(DESCRIPTION)"
                         << " " << setw(10) << "(AMOUNT)"
                         << "\t" << setw(10) << "(TIME)" << endl;

                    saving.printAllTransactions();
                }
            }
            catch (bool check)
            {
                cout << err.checkAccount() << endl;
            }
        }

        /**************************************************************
         * Option 6:
         * Method used :
         *         SavingAccount::set_InterestRate
         *         SavingAccount::get_InterestRate 
         *        SavingAccount::getInterest
         *        SavingAccount::calculateTotalBalance 
         *       BankAccountException::checkAccount
         *************************************************************/

        else if (menu_option == 6)
        {
            try
            {
                if (account_check == false)
                    throw account_check;
                else
                {
                    double new_interest;
                    cout << " --- Option6 : Set interest rate ---" << endl;
                    cout << "Please enter new rate of interest : ";
                    cin >> new_interest;
                    saving.set_InterestRate(new_interest);
                    cout << " You adjusted the interest rate to % " << saving.get_InterestRate() << endl;
                    saving.setInterest();
                    cout << "Your interest : $" << saving.getInterest() << endl;
                    saving.calculateTotalBalance();
                    saving.set_NewTotalBalance (); 
                }
            }
            catch (bool check)
            {
                cout << err.checkAccount() << endl;
            }
        }

        /**************************************************************
         * Option 7: exit the program 
         *************************************************************/

        else if (menu_option == 7)
        {
            cout << "\n*** The program exits ***\n"
                 << endl;
            break;
        }
        else
            cout << "Invalid option ! Please enter the option again. " << endl;
    }

    return 0;
}

/**************************************************************
* function : checkPassword 
* Purpose : to check for the access password 
* Parameter: 
    int counter : out 
    string password : out 
    Class err : out
    Method BankAccountException::setErr 
*************************************************************/

void checkPassword(int counter, string password)
{
    if (counter >= 2)
        throw counter;
    if (password == "abc123")
        throw password;
    else
    {
        BankAccountException err;
        err.setErr("Invalid Password");
        throw err;
    }
}
/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Project Assignment 3
 * File name : expense.cpp
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/


#include "expense.h"

using namespace std;

/**************************************************************
Declaration of constructor : Expense
* m_description (string) private class
* m_amoutn (float) private class
*************************************************************/

Expense::Expense()
{
    m_description = "";
    m_amount = 0;
}


/**************************************************************
Declaration of function : setDescription
* m_description (string) private class
*************************************************************/

void Expense::setDescription(string description)
{
    m_description = description;
}

/**************************************************************
Declaration of function : getDescription
* m_description (string) private class
*************************************************************/
string Expense::getDescription()
{
    return m_description;
}

/**************************************************************
Declaration of function : setAmount
* m_amount (float ) private class
* amount
*************************************************************/
void Expense::setAmount(float amount)
{
    m_amount = amount;
}

/**************************************************************
Declaration of function : getAmount
* m_amount (float) private class
*************************************************************/
float Expense::getAmount()
{
    return m_amount;

    
}


/**************************************************************
Declaration of function : inputData
Purpose : asking the user for the description of expense and the amount of expense
* Parameter:
* description (in)
* amount (in) 
* number (in)
*************************************************************/
void Expense::inputData()
{
    while (true)
    {
        string description;
        cout << "Please enter the description for the expense: ";
        getline(cin, description);
        if (description.empty())
            cout << "Empty description. Please input again" << endl;
        else
        {
            setDescription(description);
            break;
        }
    }

    while (true)
    {
        float amount = 0.00;
        string number;
        cout << "Enter the amount: ";
        getline(cin, number);
        amount = atof(number.c_str());
        
        if (amount <= 0 && !(isdigit(amount)))
            cout << "Invalid amount.Please input again" << endl;
        else
        {
            cout << fixed << setprecision(2);
            setAmount(amount);
            break;
        }
    }
}

/**************************************************************
Declaration of function : print
Purpose : print out the description and the amount of expense
*************************************************************/

void Expense::print()
{
    cout << fixed << setprecision(2);
    cout << "AMOUNT (" << getAmount() << ")" << setw(10) 
        << "DESC (" << getDescription() << ")"<< "\n";
}

/**************************************************************
Declaration of function : toLowerCase
Purpose : convert Upper Case to Lower Case
*************************************************************/

string Expense::toLowerCase(string aCppString)
{
    int n = aCppString.length();
    for (int i = 0; i < n; i++)
        aCppString[i] = tolower(aCppString[i]);
    return aCppString;
}

/**************************************************************
Declaration of function : searchAmount 
Purpose : search for a specific amount
*************************************************************/

void Expense::searchAmount ( Expense expenseArray[]  , int cur ) 
{   
    float searchAmount = 0.0;
    cout << "Please enter the amount: ";
    cin >> searchAmount;
    for ( int i = 0 ; i <= cur ; i++ ) {
     if (expenseArray[i].getAmount() >= searchAmount)
        expenseArray[i].print();
    }
}

/**************************************************************
Declaration of function : searchString
Purpose : search for a specific string
*************************************************************/

void Expense::searchString ( Expense expenseArray[] , int cur ) 
{
    string searchString = "";
    cout << "Please enter the search string: ";
    cin.ignore ();
    getline(cin, searchString);
    searchString = toLowerCase(searchString);
    for (int i = 0; i <= cur && !(searchString.empty()); i++) {
        if ( toLowerCase(expenseArray[i].getDescription()).find(searchString) != std::string::npos) {
             expenseArray[i].print();
            }      }
}
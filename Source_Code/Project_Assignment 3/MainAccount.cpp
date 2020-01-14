/**************************************************************
 * West Valley College - CIST 004A
 * Student : Duy Tran - 1826554
 * Project Assignment 3
 * Filename : MainAccount.cpp
 * Compiler : GCC
 * Editor: Visual Studio Code
 * ***********************************************************/

#include "expense.h"
#include <fstream>

using namespace std;

int main()
{
/**************************************************************
 * Declare type of variable and initialization
 * ***********************************************************/
    int userEnterOption = 0;
    float amount = 0.0;
    int cur = 0;
    const int capacity = 100;
    string description = "";
    string buf = "";

/**************************************************************
 * Constructor : Expense
 * Array : expenseArray[]
 * Capacity of Array : capacity
 *************************************************************/
    Expense expenseArray[capacity];

/**************************************************************
 * Main function
 *************************************************************/

    while (true)
    {

        /**************************************************************
        * Open .txt file and load data to array
        * Parameter :
        * description (in)
        * amount (in)
        * Function:
        * setDescription (in)
        * setAmount (in)
        *************************************************************/
        ifstream fin;
        fin.open("expenses.txt");
        for (int i = 0; getline(fin, description); i++)
        {
            expenseArray[i].setDescription(description);
            fin >> amount;
            fin.ignore(1000, 10);
            expenseArray[i].setAmount(amount);
            cur = i;
        }
        fin.close();

        /**************************************************************
        * Menu of program
        * Purpose : asking the user to choose optional action
        *************************************************************/

        cout << "Welcome to my expense tracker." << endl;
        cout << "Expense Tracking Menu:" << endl;
        cout << "\t1. Show all" << endl;
        cout << "\t2. Spend" << endl;
        cout << "\t3. Search expenses containing this string" << endl;
        cout << "\t4. Search expenses with greater than or equal to this amount " << endl;
        cout << "\t5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> buf;
        userEnterOption = atoi(buf.c_str());

        /**************************************************************
        * Option 1 : show all the expense 
        * Parameter:
        * cur (in)
        * Function: 
        * print() (out)
        *************************************************************/

        if (userEnterOption == 1)
        {
            fin.open("expenses.txt");
            if (fin.good())
            {
                for (int i = 0; i <= cur; i++)
                {
                    expenseArray[i].print();
                }
            }
            else
                cout << "\nThere is no expense entry available.\n"
                     << endl;
            fin.close();
        }

        /**************************************************************
        * Option 2: spend 
        * Parameter:
        * cur (in) : array elements
        * Function: 
        * getDecription() (out)
        * getAmount() (out)
        *************************************************************/
        else if (userEnterOption == 2)
        {
            cur++;
            expenseArray[cur].inputData();
            ofstream fout;
            fout.open("expenses.txt", ios_base::app);
            fout << expenseArray[cur].getDescription() << "\n"
                 << expenseArray[cur].getAmount() << "\n";
            fout.close();
        }

        /**************************************************************
        * Option 3: search for the description of expense
        * Parameter:
        * searchString (in)
        * Function: 
        * getDescription() (in)
        * toLowerCase() (out)
        * print() (out)
        *************************************************************/
        else if (userEnterOption == 3)
        {
           
            expenseArray[capacity].searchString ( expenseArray , cur ) ;
            
        }

        /**************************************************************
        * Option 4: search for the amount
        * Parameter:
        * searchAmount (in)
        * Function: 
        * getAmount() (out)
        * print() (out)
        *************************************************************/
        else if (userEnterOption == 4)
        {
            
            expenseArray[capacity].searchAmount ( expenseArray , cur) ;
        }

        /**************************************************************
        * Option 5: exit the program
        *************************************************************/
        else if (userEnterOption == 5)
        {
            cout << "\nThe program exits\n";
            break;
        }

        /**************************************************************
        * Invalid input option
        *************************************************************/
        else
            cout << "\nInvalid option. Please input again\n"
                 << endl;
    }

    return 0;
}
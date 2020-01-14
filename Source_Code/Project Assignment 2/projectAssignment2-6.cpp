/****************************************************
 * CIST 004A - WESTVALLEY COLLEGE
 * STUDENT : Duy Tran
 * Project Assignment 2
 * Code editor : Visual Studio Code
 * Compiler : GCC
 ***************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

/****************************************************
 * struct 
 * paramaters : 
   description : input user enter amount
   amount : input user enter amount
 ***************************************************/

struct expense
{
    string description;
    float amount;
};

/****************************************************
 * prototype of functions
 ***************************************************/

void getData(expense[], int i);

string toLowerCase(string aCppString);

/****************************************************
 * main function
 ***************************************************/

int main()
{
    /****************************************************
 * initialize
 ***************************************************/

    string buf;
    string buf2;
    int userEnterOption;
    const int capacity = 100;
    int cur = 0;


    /****************************************************
     * define array of struct 
     * expenseInput : array of struct
     * capacity : size of array 
     ***************************************************/

    struct expense expenseInput[capacity];

    

    cout << "Welcome to my expense tracker." << endl;

    while (true)
    {
        /**************************************************
        * read in database from expenses.txt and save to array "expenseInput"
        ***************************************************/

        ifstream fin;
        fin.open("expenses.txt");
        for (int i = 0; getline(fin, expenseInput[i].description); i++)
        {
            //int i = 0;
            fin >> expenseInput[i].amount;
            fin.ignore(1000, 10);
            cur = i;
        }
        fin.close();
        

        /****************************************************
        * Main Menu
        * Purpose : ask user to input option number
        ***************************************************/

        cout << "Expense Tracking Menu:" << endl;
        cout << "\t1. Show all" << endl;
        cout << "\t2. Spend" << endl;
        cout << "\t3. Search expenses containing this string" << endl;
        cout << "\t4. Search expenses with greater than or equal to this amount " << endl;
        cout << "\t5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> buf;
        userEnterOption = atoi(buf.c_str());

        /****************************************************
        * Option 1 : show history of of spending
        * Paramater :
            expenseInput : array of struct 
            int i : element of array
        ***************************************************/
        if (userEnterOption == 1)
        {
            ifstream fin;
            fin.open("expenses.txt");
            if (fin.good())
            {

                for (int i = 0; getline(fin, expenseInput[i].description); i++)
                {
                    //int i = 0;
                    cout << i << " ";
                    fin >> expenseInput[i].amount;
                    fin.ignore(1000, 10);
                    cout << "AMOUNT (" << expenseInput[i].amount << ")" << setw(10)
                         << "DESC (" << expenseInput[i].description << ")"
                         << "\n";
                }
            }
            else
                cout << "\nThere is no expense entry available.\n"
                     << endl;
            fin.close();
        }

        /****************************************************
        * Option 2 : spend 
        * Purpose : ask user about description and amount , and save all data into expenses.txt
        * Parameter:
          expenseInput : input 
          cur : input - element
        ***************************************************/
        else if (userEnterOption == 2)
        {
            cur++;
            getData(expenseInput, cur);
            ofstream fout;
            fout.open("expenses.txt", std::ios_base::app);
            fout << expenseInput[cur].description << "\n"
                 << expenseInput[cur].amount << "\n";
            fout.close();
        }

        /****************************************************
        * Option 3 : Search expenses containing this string
        * Purpose : show the description and its amount which match the string user want to find
        * paramater : 
          searchString : input 
        ***************************************************/
        else if (userEnterOption == 3)
        {
            string searchString;
            cout << "Please enter the search string: ";
            cin.ignore();
            getline(cin, searchString);
            toLowerCase(searchString);
            searchString = toLowerCase(searchString);

            for (int i = 0; i < capacity; i++)
            {
               toLowerCase(expenseInput[i].description);
                if (toLowerCase(expenseInput[i].description).find(searchString) != std::string::npos && !(toLowerCase(searchString).empty()) )
                {
                    cout << "AMOUNT (" << expenseInput[i].amount << ")" << setw(10)
                         << "DESC (" << expenseInput[i].description << ")"
                         << endl;
                }
                else 
                    break;
            }
        }

        /****************************************************
        * Option 4 : Search expenses containing this amount
        * Purpose : show the amounts and their descriptions which are equal or greater than the number user want to find
        * paramater : 
          searchAmount : input 
        ***************************************************/

        else if (userEnterOption == 4)
        {
            double searchAmount;
            cout << " Please enter the search amount: ";
            cin >> searchAmount;
            for (int i = 0; i < capacity; i++)
            {
                if (expenseInput[i].amount >= searchAmount)
                    cout << "AMOUNT (" << expenseInput[i].amount << ")" << setw(10)
                         << "DESC (" << expenseInput[i].description << ")"
                         << endl;
            }
        }

        /****************************************************
        * Option 5 : exit the menu
        * Purpose : exit and 
        ***************************************************/
        else if (userEnterOption == 5)
            break;
        else
            cout << "\nYour input is invalid. Please enter valid option: \n"
                 << endl;
    }

    return 0;
}

/****************************************************
* void function : getData
* Purpose : ask the user to enter the description and amount for exepense
* paramater :
    expenseInput[].description : input 
    expenseInput[].amount : input
    amount : input
***************************************************/
void getData( expense expenseInput[], int i)
{
    while (true)
    {  
        cout << "Please enter the description for the expense: ";
        getline(cin, expenseInput[i].description);
        if (expenseInput[i].description.empty())
            cout << "Empty description. Please input again" << endl;
        else
            break;
    }

    while (true)
    {
        string amount;
        cout << "Enter the amount: ";
        cin >> amount;
        expenseInput[i].amount = atof(amount.c_str());
        cin.ignore(1000, 10);
        if (atof(amount.c_str()) <= 0 && !(isdigit(atof(amount.c_str()))))
            cout << "Invalid amount.Please input again" << endl;
        else
            break;


    }
}

/****************************************************
* void function : string toLowerCase
* Purpose : convert elements of expenseInput[] to lowercase
* paramater :
    aCppString (IN) : string
    return aCppString
***************************************************/
string toLowerCase(string aCppString)
{
    int n = aCppString.length();
    for (int i = 0; i < n; i++)
        aCppString[i] = tolower(aCppString[i]);
    return aCppString;
}

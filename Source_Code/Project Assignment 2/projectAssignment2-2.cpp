#include <iostream>
// #include <struct> 
#include <cstdlib>
#include <fstream>

#include <string>

using namespace std;

 struct expense
{
    string description;
    double amount;
};

void getData ( expense& expenseInput);

int main()
{

    string buf;
    string buf2;
    int userEnterOption;

    cout << "Welcome to my expense tracker." << endl;
    
    while (true)
    {
        cout << "Expense Tracking Menu:" << endl;
        cout << "\t1. Show all" << endl;
        cout << "\t2. Spend" << endl;
        cout << "\t3. Search expenses containing this string" << endl;
        cout << "\t4. Search expenses with greater than or equal to this amount " << endl;
        cout << "\t5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> buf;
        userEnterOption = atoi(buf.c_str());

     expense expenseInput;
        expenseInput.description = "unknown";
        expenseInput.amount = 0;

        if (userEnterOption == 1)
        {
            ifstream fin;
            fin.open("expenses.txt");
            if (fin.good())
            {   
                cin.ignore();
                getline(fin, expenseInput.description);
                fin >> expenseInput.amount;
                fin.ignore(1000, 100);
                cout << "AMOUNT (" << expenseInput.amount << ")\t" 
                 << "DESC (" << expenseInput.description << ")" << endl;
            } else 
            { cout << "There is no expense entry available." << endl; }
            fin.close();
        } else if (userEnterOption == 2)
        {   
            getData (expenseInput);
            ofstream fout;
            fout.open("expenses.txt");
            fout << expenseInput.description << "\n"
                 << expenseInput.amount << "\n";
            fout.close();
            
        }
        else if (userEnterOption == 5)
            break;
        else
            cout << "Your input is invalid. Please enter valid option: " << endl;
    }

    return 0;
}

void getData ( expense& expenseInput )
{  
    string buf2;
    cout << "Please enter the description for the expense: ";
    cin.ignore();
    getline(cin,expenseInput.description);
    cout << "Enter the amount: ";
    cin >> buf2;
    expenseInput.amount = atof(buf2.c_str());
    cin.ignore(1000, 10);
}
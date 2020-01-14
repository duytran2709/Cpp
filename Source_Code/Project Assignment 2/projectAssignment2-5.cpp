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

void getData(expense[], int i);

int main()
{

    string buf;
    string buf2;
    int userEnterOption;
    int capacity = 100;
    int i = 0;
    int j = 0;

    struct expense expenseInput[capacity];

    cout << "Welcome to my expense tracker." << endl;

    while (true)
    {
        ifstream fin;
        fin.open("expenses.txt");

        while (getline(fin, expenseInput[i].description))
        {
            int i = 0;
            fin >> expenseInput[i].amount;
            fin.ignore(1000, 10);
            i++;
        }

        cout << "Expense Tracking Menu:" << endl;
        cout << "\t1. Show all" << endl;
        cout << "\t2. Spend" << endl;
        cout << "\t3. Search expenses containing this string" << endl;
        cout << "\t4. Search expenses with greater than or equal to this amount " << endl;
        cout << "\t5. Exit" << endl;
        cout << "Enter your option: ";
        cin >> buf;
        userEnterOption = atoi(buf.c_str());

        // expenseInput[i].description = "unknown";
        // expenseInput[i].amount = 0;

        if (userEnterOption == 1)
        {
            ifstream fin;
            fin.open("expenses.txt");
            if (fin.good())
            {
                while (getline(fin, expenseInput[i].description))
                {
                    int i = 0;
                    fin >> expenseInput[i].amount;
                    fin.ignore(1000, 10);
                    cout << "AMOUNT (" << expenseInput[i].amount << ")\t"
                         << "DESC (" << expenseInput[i].description << ")"
                         << "\n";
                    i++;
                }
            }
            else
                cout << "There is no expense entry available." << endl;
            fin.close();
        }
        else if (userEnterOption == 2)
        {

            getData(expenseInput, j);
            ofstream fout;
            fout.open("expenses.txt", std::ios_base::app);
            fout << expenseInput[j].description << "\n"
                 << expenseInput[j].amount << "\n";
            fout.close();
            j++;
        }
        else if (userEnterOption == 5)
            break;
        else
            cout << "Your input is invalid. Please enter valid option: " << endl;
        fin.close();
    }

    return 0;
}

void getData(expense expenseInput[], int i)
{
    string buf2;
    cout << "Please enter the description for the expense: ";
    cin.ignore();
    getline(cin, expenseInput[i].description);

    // cout << "Enter the amount: ";
    // cin >> buf2;
    while (true)
    {
        cout << "Enter the amount: ";
        cin >> buf2;
        expenseInput[i].amount = atof(buf2.c_str());
        cin.ignore(1000, 10);
        if (atof(buf2.c_str()) <= 0  && ! (isdigit(atof(buf2.c_str()))))
            cout << " Invalid amount.Please input again" << endl;
        else
            break;
    }
    // expenseInput[i].amount = atof(buf2.c_str());
    // cin.ignore(1000, 10);
}
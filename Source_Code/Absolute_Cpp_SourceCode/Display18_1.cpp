// Display 18.1 : handling a Special Case without Exception handling
//                    file name : Display18_1.cpp

#include <iostream>
using namespace std;

int main()
{
    int donuts, milk;
    double dpg;
    cout << "Enter number of donuts: \n";
    cin >> donuts;
    cout << "Enter number of glasses of milk : \n";
    cin >> milk;

    if (milk <= 0)
    {
        cout << donuts << " donuts , and No Milk!\n"
        << "Go buy some milk. \n";
    }

    else
    {
        dpg = donuts / static_cast<double>(milk);
        cout << donuts << " donuts.\n"
             << milk << "glasses of milk \n"
             << "you have " << dpg
             << " donuts for each glass of milk . \n";
    }

    cout << "End of program.\n";
    return 0;
}
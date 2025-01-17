//Display 18.2 : Same thing Using Exception Handling

#include <iostream>
using namespace std;

int main()
{
    int donuts, milk;
    double dpg;

    try
    {
        cout << "Enter number of donuts: \n";
        cin >> donuts;
        cout << "Enter number of glasses of milk: \n";
        cin >> milk;

        if (milk <= 0)
            throw donuts;

        dpg = donuts / static_cast<double>(milk);
        cout << donuts << " donuts.\n"
             << milk << " glasses of milk.\n"
             << "You have " << dpg
             << "Donuts for each glass of milk.\n";
    }
    catch (int e)
    {
        cout << e << "donuts , and No Milk !\n"
             << "Go buy some milk.]n";
    }

    cout << "End of program.\n ";
    return 0;
}
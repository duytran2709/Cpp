//Display 15.5 Use of a virtual function
//Absolute C++ 
// demonstrates the performance of the virtual function bill

#include <iostream>
#include "sale.h" 
#include "discountsale.h"

using namespace std;

using namespace SavitchSale;

int main () 
{
    Sale simple (10.00) ; // one item at $ 10.00.
    DiscountSale discount (11.00, 10); // one items at $11.00 with a 10% discount 

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (discount < simple )
    {
        cout << "Discounted item is cheaper.\n";
        cout << "Saving is $" << simple.savings(discount) << endl;
    }

    else 
    cout << "Discounted item is not cheaper.\n";

    return 0;

}
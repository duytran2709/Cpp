//Absolute C++
// Display 10.12
// Demonstration Program for PDArrayD

#include "PFArrayD.h"

void testPFArrayD ();
//Conducts one test of the class PFArrayD

int main ()
{
    cout << "This program tests the class PFArrayD\n";

    char ans;
    do 
    {
        testPFArrayD();
        cout << "Test again? (y/n)" ;
        cin >> ans;
    }
    while (( ans == 'y' ) || ( ans == 'Y' ));

    return 0;
}

void testPFArrayD ()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonegative numbers. \n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ( (next >= 0) && ( !temp.full ()))
    {
        temp.addElement ( next);
        cin >> next;

    }

    cout << "You entered the following " 
    << temp.getNumberUsed () << " numbers: \n";

    int index;
    int count = temp.getNumberUsed();
    for (index = 0 ; index < count ; index ++)
    cout << temp[index] << " " ;
    cout << endl;
    cout << "plus a sentinel value.\n";
}
#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"

using namespace std;

int main ()
{
    // instantiate a CommissionEmployee object 
    CommissionEmployee employee ( "Sue" , "Jones" , "222-222-2222" , 10000, .06 );

    //set floating-point output formatting
    cout << fixed << setprecision (2);

    cout << " Employee information obtained by get function: " << endl;
    cout << "\nFirst name is " << employee.getFirstName ();
    cout << "\nLast name is " << employee.getLastName ();
    cout << "\nSocial security number is " << employee.getSocialSecurityNumber ();
    cout << "\nGross sales is " << employee.getGrossSales();
    cout << "\nCommission rate is " << employee.getCommissionRate() << endl;

employee.setGrossSales (8000) ; //set gross sales
employee.setCommissionRate (.1) ; // set commission rate
cout << "\nUpdated employee information output by print function: \n" << endl;
employee.print () ; //display the new employee information

//display the employee's earnings
cout << "\n\nEmployee's earnings: &" << employee.earning() << endl;
}
//Fig 11.5: CommissionEmployee.cpp
// Class CommissionEmployee member-function definitions.

#include <iostream>
#include <stdexcept>

#include "CommissionEmployee.h"
using namespace std;

//constructor
CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate)

{
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

//set first name
void CommissionEmployee::setFristName(const string &first)
{
    firstName = first;
}

//return first name
string CommissionEmployee::getFirstName() const
{
    return firstName;
}

//set last name
void CommissionEmployee::setLastName(const string &last)
{
    lastName = last;
}

//return last name
string CommissionEmployee::getLastName() const
{
    return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const

{
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales)
{
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument(" Gross sales must be >= 0.0 ");
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate)
{
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

//return commision rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

double CommissionEmployee::earning() const
{
    return commissionRate * grossSales;
}

void CommissionEmployee::print() const
{
    cout << "commision employee: " << firstName << ' ' << lastName
         << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate;
}

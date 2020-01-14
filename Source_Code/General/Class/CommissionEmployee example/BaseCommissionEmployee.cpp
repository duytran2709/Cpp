//Class BaseCommissionEmployee member-function definitions.

#include <iostream>
#include <stdexcept>
#include "BaseCommissionEmployee.h"

using namespace std;

//constructor

BaseCommissionEmployee::BaseCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary)
    //explicitly call base-class constructor
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

void BaseCommissionEmployee::setBaseSalary(double salary)
{
    if (salary >= 0.0)
        baseSalary = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
}

double BaseCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

double BaseCommissionEmployee::earnings() const
{
    // return baseSalary + (commissionRate * grossSales);

    return getBaseSalary () + CommissionEmployee::earning();
}

void BaseCommissionEmployee::print() const
{
    cout << "base-salaried" ;

    //invoke CommissionEmployee's print function
    CommissionEmployee::print ();
    
    cout   << "\nbase salary: " << getBaseSalary() ;
}

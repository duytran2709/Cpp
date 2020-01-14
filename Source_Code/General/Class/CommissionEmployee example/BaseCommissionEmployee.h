//BaseCommissionEmployee class derived from class CommissionEmployee

#ifndef BASECOMMISSIONEMPLOYEE_H
#define BASECOMMISSIONEMPLOYEE_H

#include <string>
#include "CommissionEmployee.h" // CommissionEmployee class declaration

using namespace std;

class BaseCommissionEmployee : public CommissionEmployee
{
  public:
    BaseCommissionEmployee(const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;

  private:
    double baseSalary;
};

#endif

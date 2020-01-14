// Fig.11.4: CommissionEmployee.h
// CommisionEmployee class definition represents a commission employee.

#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>

using namespace std;

class CommissionEmployee
{

  public:
    CommissionEmployee(const string &, const string & , const string &, double = 0.0, double = 0.0);

    void setFristName(const string &);
    string getFirstName() const;

    void setLastName(const string &);
    string getLastName() const;

    void setSocialSecurityNumber(const string &);
    string getSocialSecurityNumber() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    double earning() const;
    void print() const;

  protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif
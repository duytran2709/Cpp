#include <iostream>
#include <cstdlib>

using namespace std;

class DayOfYear
{
  public:
    DayOfYear(int monthValue, int dayValue);

    DayOfYear(int monthValue);

    DayOfYear();

    void input();
    void output();
    int getMonthNumber();
    int getDay();

  private:
    int month;
    int day;
    void testDate();
};

int main()
{
    DayOfYear date1(2, 21), date2(5), date3;
    cout << "Initialized dates: " << endl;
    date1.output();
    cout << endl;
    date2.output();
    cout << endl;
    date3.output();
    cout << endl;

    date1 = DayOfYear(10, 31);
    cout << "date1 reset to the following: " << endl;
    date1.output();
    cout << endl;
    return 0;
}

DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue)
{
    testDate();
}

DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1)
{
    testDate();
}

DayOfYear::DayOfYear() : month(1), day(1)
{
}

void DayOfYear::testDate()
{
    if ((month < 1) || (month > 12))
    {
        cout << "Illegal month value!" << endl;
        exit(1);
    }
    if ((day < 1) || (day > 31))
    {
        cout << "Illegal day value !" << endl;
        exit(1);
    }
}

int DayOfYear::getMonthNumber()
{
    return month;
}

int DayOfYear::getDay()
{
    return day;
}

void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        cout << " Illegal date! Program abroted.";
        exit(1);
    }
}

void DayOfYear::output()
{
    switch (month)
    {
    case 1:
        cout << "January";
        break;
    case 2:
        cout << "Febuary";
        break;
    case 3:
        cout << "March";
        break;
    case 4:
        cout << "April";
        break;
    case 5:
        cout << "May";
        break;
    case 6:
        cout << "June";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 9:
        cout << "September";
        break;
    case 10:
        cout << "October";
        break;
    case 11:
        cout << "Febuary";
        break;
    case 12:
        cout << "Febuary";
        break;
    default:
        cout << "Error in DayOfYear::ouput";
    }
    cout << day;
}
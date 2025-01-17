// Absolute.CPP.5th.Edition
// Display 4.1 : Formal Parameter Used as a Local Variable 
// Law Office billing program.

#include <iostream> 
using namespace std; 

const double RATE = 150.00; // Dolars per quarter hour.

double fee ( int hoursWorked, int minutesWorked ) ; 
//returns the charges for hoursWorked hours and
// minutesWorked minutes of legal services

int main () 
{
    int hours minutes; 
    double bill; 

    cout << "Welcome to the lay office of \n"
        << "Dewey, Cheatham, and Howe.\n " 
        << "The law office with a heart. \n" 
        << "Enter the hours and minutes"
        << " of your consultation: \n " ; 
    cin >> hours >> minutes; 

    bill = fee (hours , minutes ) ; 
    cout.setf(ios::fixed ) ; 
    cout.setf(ios::showpoint ) ; 
    cout.precision(2) ; 
    cout << " For " << hours << " hours and " << minutes 
        << " minutes, your bill is & " << bill << endl;

    return 0 ;
}

double fee ( int hoursWorked, int minutesWorked ) 
{
    int quarterHours; 

    minutesWorked = hoursWorked*60 + minutesWorked; 
    quarterHours = minutesWorked/15; 
    return (quarterHours*RATE) ; 
}


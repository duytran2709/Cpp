#include <iostream>
#include <string>

using namespace std;

bool name ( char grade );

int main ()
{

    char grade = 0;
    

cout << " please enter your grade : " << endl;
    cin >> grade;
    
    cout << boolalpha << name ( grade ) << endl;
    

    return 0;
}

bool name ( char grade )
{
    switch ( grade )
    {
    case 'a':
        {cout << "Excellent" ; grade = true ; break;  }
    }
    return grade;
}

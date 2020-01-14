#include <iostream>
#include <ctime>

using namespace std;

int main()
{
   // get current date and time in milliseconds
   time_t  Time = time(NULL) ;

   cout << "Current date and time is: " << ctime(&Time) << endl ;

   return 0;
}

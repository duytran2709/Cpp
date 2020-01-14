#include <iostream>
#include <struct> 
#include <cstdlib>

using namespace std;


Struct 

int main()
{


string buf;
int userEnterOption;

cout << "Welcome to my expense tracker." << endl;

cout << "Expense Tracking Menu:" << endl;
cout << "\t1. Show all" << endl;
cout << "\t2. Spend" << endl;
cout << "\t3. Search expenses containing this string" << endl;
cout << "\t4. Search expenses with greater than or equal to this amount " << endl;
cout << "\t5. Exit" << endl;
cout << "Enter your option: " ;
cin >> buf; 

userEnterOption = atoi(buf.c_str());



 


return 0;

}
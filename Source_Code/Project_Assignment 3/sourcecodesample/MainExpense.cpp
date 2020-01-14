#include "Expense.h"

#include <iostream>
using namespace std;



int main()
{
    Expense expenses[100];

	cout << "Welcome to Tracking Expense Program." << endl;
		
	expenses[0].setDesc("Netflix membership");
	expenses[0].setCost(7.99); 
	
	expenses[0].m_desc = "Gym membership";
	
	expenses[0].print();
	
	cout << expenses[0].getCost() << endl;
	

		
    return 0 ;
}


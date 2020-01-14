#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#define MAX_EXPENSES  100

struct Expense
{
  string desc; // description
  float amount; // cost amount
};

void searchByDesc(string, Expense [], int);

int main( )
{
  Expense expenses[MAX_EXPENSES];  // static array
  int size = 2;
  
  expenses[0].desc = "Netflix membership";
  expenses[0].amount = 7.99;
  expenses[1].desc = "car payment";
  expenses[1].amount = 187.99;
 
  string target = "membership";
  searchByDesc(target, expenses, size);
 
  string target2 = "not found";
  searchByDesc(target2, expenses, size);

  int num_expense;
  cout << "Enter max number of expenses: " << endl;
  cin >> num_expense;
  Expense *expPtr = new Expense[num_expense]; // dynamic array
  
  expPtr[0].desc = "Gym membership";
  expPtr[0].amount = 34.95;

  delete [] expPtr;   // return allocated memory back to system
  
  return 0;
}

void searchByDesc(string targetDesc, Expense expList[], int size)
{
  for (int i = 0; i < size; i++)
  {
	int pos = expList[i].desc.find(targetDesc);
	if (pos != std::string::npos)
	  cout << "Found: " << targetDesc << " in: " << expList[i].desc << endl;
  }
  
  cout << "Exit searchByDesc().\n" << endl;
}



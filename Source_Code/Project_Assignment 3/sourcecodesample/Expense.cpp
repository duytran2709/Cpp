#include <iostream>

#include <string>
using namespace std;

#include "Expense.h"

Expense::Expense()
{
    m_cost = 0;
	m_desc = "";
}


float   Expense::getCost() const
{
    return ( m_cost);
}

void   Expense::setCost(float cost)
{
    m_cost = cost;
}

void   Expense::setDesc(string desc)
{
    m_desc = desc;
}

void     Expense::print() const
{
    cout << "Description: " << m_desc << "\t cost: $" << m_cost << endl;
}

void Expense::searchAmount ( int cur , float searchAmount ) 
{   
    Expense expenseArray[100] ;
    for (int i = 0; i <= cur; i++)
            {
                if (expenseArray[i].getAmount() >= searchAmount)
                    expenseArray[i].print();
            }
}



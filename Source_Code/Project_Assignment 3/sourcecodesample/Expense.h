#ifndef EXPENSE_H 
#define EXPENSE_H 

#include <iostream>
#include <string>
using namespace std;  // Need this so that you don't need std::string

class Expense
{
    private:
        string m_desc;
		float  m_cost;

    public:
	    Expense();  // default constructor
		//??? (string desc, float cost); // constructor
		
		/* You fill in the method description    */
        bool  contain(std::string target);
		
		//string getDesc() const;
		void setDesc(string desc);
		
		float getCost() const;
		void  setCost(float cost);
		
		/**
        *  represent the Expense object as a string
        */
		
        string toString() const;
		
		void     print() const ;
};


#endif

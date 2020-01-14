#ifndef BANKACCOUNT2_H 
#define BANKACCOUNT2_H 

class BankAccount
{
    private:
         int         m_id ;
		
	protected:
         double      m_balance ;

     public:
	    BankAccount() ;
		BankAccount(double initialBalance);
        bool     deposit(double amount);
        bool     withdraw(double amount);
        double   balance() const;
		void     print() const ;
};

class SavingAccount : public BankAccount
{
     private:
         int         m_year_opened ;
         double      m_interest_rate;

     public:
		SavingAccount(double, int, double);
		void     print() const ;  // Override super's class method

};

#endif

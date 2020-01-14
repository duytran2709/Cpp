#include <iostream>
#include <string>

// To use Exception
#include <stdexcept>
using namespace std;

// User-defined exception "InvalidPrice"
class InvalidPrice : public runtime_error
{
    public:
	  // Initializer: call superclass'constructor
      InvalidPrice(string errMsg) : runtime_error(errMsg)
      {
      }
      void why()
      {
         cout << "I cannot have an item with negative price." << endl;
      }
};

class Item
{
   private:
      double  m_price ;
   public:
      Item(double price) : m_price(price)
      {
         if (price < 0)
           throw InvalidPrice("Price cannot be negative, please. ") ;
      }
      string toString() const
      {
          return "COST(" + to_string(m_price) + ")" ;
      }
};

double getAmount()
{
   double amount = -1 ;
   do
   {
     cout << "Please enter an amount: " ;
     cin >> amount ;
     if (cin.fail())
     {
        cout << "Error. You did not give me the number." << endl ;
        cin.clear() ;
        cin.ignore(1024, '\n');
     }
   } while (amount < 0) ;
   return amount ;
}

double getAmountWithErrorHandling()
{
   double amount ;
   cout << "Please enter an amoun.t: " ;
   cin >> amount ;
   if (cin.fail())
   {
     //throw runtime_error("Invalid Number. I am expecting only number, please.") ;
     throw exception() ;
   }
   return amount ;
}


int main()
{
   // cout << "Amount: " << getAmount() << endl ;
   try
   {
     cout << "Amount: " << getAmountWithErrorHandling() << endl ;
     cout << "Read the amount successfully" << endl;
   }
   catch(exception & err)  // Logic error
   {
     cout << "A general error has occurred. " << endl;
   }
   catch(runtime_error & err1)
   {
     cout << err1.what() << endl;
   }
   catch(runtime_error & err2)  // catch same type twice
   {
     cout << err2.what() << endl;
   }


   Item item1(99.99);
   cout << item1.toString() << endl ;

   try
   {
      Item item2(-88.88);
      cout << item2.toString() << endl ;
   } 
   catch(InvalidPrice &err1 ) // compiling errors
   {
     err1.why() ;
   }

   catch ( runtime_error &err2) 
   {
     err2.what () ;
   }
 

   cout << "End of program. Thank you. " << endl;
   return 0;
}
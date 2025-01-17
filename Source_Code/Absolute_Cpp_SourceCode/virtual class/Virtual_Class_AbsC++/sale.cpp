//Display 15.2 Implementation of the Base Class Sale
// this is the file sale.cpp
// this is the implementation for the class Sale.
// the interface for the class Sale is in the file sale.h.

#include <iostream>
#include "sale.h"

using namespace std;
namespace SavitchSale
{
    Sale::Sale () : price (0)
    {
        //intentionally empty
    }

    Sale::Sale (double thePrice)
    {
        if (thePrice >= 0)
        price = thePrice;
        else {
            cout << "Error: cannot have a negative price!\n";
            exit (1);

        }
   }
   double Sale::bill() const{
       return price;
   }

   double Sale::getPrice () const{
       return price;
   }

   void Sale::setPrice (double newPrice)
   {
       if (newPrice >= 0)
       price = newPrice;
       else 
       {
           cout << "Error: cannot have a negative price\n";
           exit (1);
       }
   }

   double Sale::savings (const Sale &other) const
   {
       return (bill() - other.bill ()) ;
   }

   bool operator < (const Sale& first, const Sale& second)
   {
       return (first.bill () < second.bill () );
   }
}// SavitchSale

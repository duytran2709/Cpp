//Display 15.3 Interface for the Derived Class DiscountSale 
// this is the file discountsale.h
// this is the interface for the class DiscountSale.

#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H

#include "sale.h"

namespace SavitchSale
{
    class DiscountSale : public Sale
    {
        public: 
        DiscountSale ();
        DiscountSale (double thePrice, double theDiscount );
        //Discount is expressed as a percentage of the price.
        // A negative discount is a price increase.

        double getDiscount () const;
        void setDiscount (double newDiscount);
        double bill () const; 
        // Since "bill" was declared virtual in the base class, it is automatically
        // virtual in the derived class DiscountSale. 
        // You can add the modifier "virtual" to the declaration of "bill" or omit it as here;
        // in either case "bill" is virtual in the class DiscountSale.
        // (We prefer to include the word "virtual" in all virtual function declarations,
        // even if it is not required. We omitted it here to illustrate that it is not required.)
        private:
        double discount;
    };
} // SavitchSale'

#endif

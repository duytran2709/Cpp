//Display 15.1 Interface for the Base Class Sale
//Absoulute C++
//this is the header file sale.h
//This is the interface for the class Sale.
//Sale is a class for simple sales.

#ifndef SALE_H
#define SALE_H

namespace SavitchSale
{
class Sale
{
  public:
    Sale();
    Sale(double thePrice);
    double getPrice() const;
    void setPrice(double newPrice);
    virtual double bill() const;
    double savings (const Sale &other) const;
    //Return the savings if you buy other instead of the calling object.
  private:
    double price;
};

bool operator < (const Sale &first, const Sale &second);
//Compare two sales to see which is larger.
} // SavitchSale

#endif

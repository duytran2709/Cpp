//Definition of a Class with a Dynamic Array Member
// Display 10.10
// Absolute C++ 


#include <iostream>

using namespace std;

#ifndef PFARRAYD_H
#define PFARRAYD_H

class PFArrayD
{
    public: 
    PFArrayD();
    //Initializes with a capacity of 50.

    PFArrayD(int capacityValue);

    PFArrayD(const PFArrayD& pfaObject);

    void addElement ( double element);
    //Precondition: The array is no full.
    //Postcondition: The element has been added.

    bool full () const { return (capacity == used) ;}
    //Return true if the array is full, false otherwise.

    int getCapacity () const { return capacity ; }
    
    int getNumberUsed () const { return used;} 

    void emptyArray () { used = 0; }
    //Empties the array.

    double& operator [] (int index);
    //Read and change access to element 0 through numberUsed - 1.

    PFArrayD& operator = ( const PFArrayD& rightSide );

    ~PFArrayD ();

    private: 
    double *a ; // For an array of doubles
    int capacity; // For the size of the array
    int used; // For the number of array positions currently in use 

};

#endif
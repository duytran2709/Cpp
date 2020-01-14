//Fig 17.2 : fig17_02.cpp
//Example that throws exception on 
//Attemps to divide by zero.
#include "DivideByZeroException.h"
#include <iostream>
using namespace std;

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient(int numerator, int denominator) 
{
    // throw DivideByZeroException if trynig to divide by zero
    if (denominator == 0) 
    throw DivideByZeroException();

    // return division result
    return static_cast<double>(numerator) / denominator;
}

int main(int argc, const char *argv[])
 {
    int number1;
    int number2;
    double result;

    std::cout << "Enter two integers (end-of-file to end): ";

    // enable users to enter two integers to divide
    while (std::cin >> number1 >> number2) {
        // try block contains code that might throw exception
        // and code that will not execute if an exception occurs
        try {
            result = quotient(number1, number2);
            std::cout << "The quotient is: " << result << std::endl;
        } catch (DivideByZeroException &divideByZeroException) {
            std::cout << "Exception occured: " << divideByZeroException.what()
                      << std::endl;
        }
        std::cout << "\nEnter two integers (end-of-file to end): ";
    }
    std::cout << std::endl;

    return 0;
}

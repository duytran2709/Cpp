// Absolute.CPP.5th.Edition
// Display 4.4 Inadvertent Local Variable
// Program to demonstrate call-by-reference parameters.
#include <iostream>
using namespace std;

void getNumbers(int &input1, int &input2);
//Reads two integers from the keyboard.

void swapValues(int variable1, int variable2);
//Interchanges the values of variable1 and variable2.

void showResults(int output1, int output2);
//Show the values of variable1 and variable2 , in that order.

int main()
{
    int firstNum, secondNum;

    getNumbers(firstNum, secondNum);
    swapValues(firstNum, secondNum);
    showResults(firstNum, secondNum);

    return 0;
}

void swapValues(int variable1, int variable2)
{
    int temp;
    temp = variable1;
    variable1 = variable2;
}
#include <iostream>

using namespace std;

class Sally
{
    public: 
        int num; 
        Sally ()
        {};
        Sally ( int a )
        {
            num = a ; 
        };
        Sally operator+ ( Sally  aso) 
        {
            Sally number;
            number.num = num + aso.num;
            return number ;
        }; 
}; 

int main () 
{
    Sally a (31);
    Sally b ( -54 ) ;
    Sally c ; 

    c = a + b ; 
    cout << c.num << endl; 
    return 0; 
}
#include <iostream>
#include <exception>
using namespace std;

class OverSpeed : public exception
{
    int speed;

  public:
    const char* what()
    {
        return "check out ur car speed \n you are in car not in the aeroplane \n";
    }

    void getSpeed()
    {
        cout << "Your car speed is " << speed << endl;
    }

    void setSpeed(int speed)
    {
        this->speed = speed;
    }
};

class Car
{
    int speed;

  public:
    Car()
    {
        speed = 0;
        cout << "speed is " << speed << endl;
    }

    void accelarate()
    {
        for (;;)
        {
            speed += 10;
            cout << "speed is " << speed << endl;
            if (speed >= 250)
            {
                OverSpeed s;
                s.setSpeed(speed);
                throw s;
            }
        }
    }
};

int main()
{
    Car anilscar ;
    try {
        anilscar.accelarate () ;

    }

    catch ( OverSpeed s ) {
        cout << s.what () << endl;
        s.getSpeed () ;
    }
    return 0;
}
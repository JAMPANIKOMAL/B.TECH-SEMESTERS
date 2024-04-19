//Type Conversion
//01. Class to Basic type conversion using casting operator function..

#include <iostream>
using namespace std;              

class sample
{
    private:
        float a;

    public:
        sample() 
        {
            a = 10.23;
        }

        operator int()    //Casting operator function   1. No return type  2. no arguments
        {
            int x;
            x = a;
            return x;
        }


};

int main()
{
    cout << endl;

    sample s;
    //int y = s;    //y = int (s);  --> Explicit type conversion. 

    int y;
    y = (int) s;

    cout << "The value of y = " << y;

    cout << endl << endl;

    return 0;
}
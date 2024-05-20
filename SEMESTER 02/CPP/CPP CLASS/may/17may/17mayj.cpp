//complete this code from ppt.

#include <iostream>
using namespace std;

class base
{
    public:
        int b;
        void show()
        {
            cout << "b = " << b << endl;
        }
};

class derived : public base
{
    public:
        int d;
        void show()
        {
            cout << "b = " << b << endl << "d = " << d <<  endl;
        }
};

int main()
{
    cout << endl;

    base b1;
    derived d1;
    base * bptr;
    bptr = &b1;
    bptr -> b = 100;
    bptr -> show();
    cout << endl;

    bptr = &d1;
    bptr -> b = 200;
    bptr -> show();
    cout << endl;

    derived * dptr;
    dptr = &d1;
    dptr -> d = 300;
    dptr -> show();

    // derived * d2;
    // base b2;
    // d2 = &b2;
    // b2 -> s
    
    // cout << endl;
    
    return 0;
}
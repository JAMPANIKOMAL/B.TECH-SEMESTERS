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
            cout << "b = " << b << "d = " << d <<  endl;
        }
};

int main()
{
    cout << endl;

    base b1;
    derived d1;
    base * bptr;
    bptr = &b1;


    return 0;
}
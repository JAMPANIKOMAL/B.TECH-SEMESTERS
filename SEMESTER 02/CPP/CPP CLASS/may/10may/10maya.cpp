//3. Multiple Inheritance
//2 BASE CLASS 1 DERIVED CLASS MOTHER FATHER SON

#include <iostream>
using namespace std;

class Liquid
{
    public:
        void display1()
        {
            cout << "Liquid Class" << endl;
        }
};

class Fuel
{
    public:
        void display2()
        {
            cout << "Fuel Class" << endl;
        }
};

class Petrol : public Liquid, public Fuel
{
    public:
        void display3()
        {
            cout << "Petrol Class" << endl;
        }
};


int main()
{
    cout << endl;

    Liquid l;
    Fuel f;
    Petrol p;

    l.display1();
    cout << endl;

    f.display2();
    cout << endl;

    p.display3();
    p.display2();
    p.display1();
    cout << endl;

    return 0;
}
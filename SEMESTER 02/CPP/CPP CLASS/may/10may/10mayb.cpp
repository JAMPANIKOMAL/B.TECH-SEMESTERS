//3. Multiple Inheritance

#include <iostream>
using namespace std;

class Liquid
{
    public:
        void display_Liquid()
        {
            cout << "Liquid Class" << endl;
        }
};

class Fuel
{
    public:
        void display_Fuel()
        {
            cout << "Fuel Class" << endl;
        }
};

class Petrol : public Liquid, public Fuel
{
    public:
        void display_Petrol()
        {
            cout << "Petrol Class" << endl;
            display_Fuel();
            display_Liquid();
        }
};


int main()
{
    cout << endl;

    Liquid l;
    Fuel f;
    Petrol p;

    l.display_Liquid();
    cout << endl;

    f.display_Fuel();
    cout << endl;

    p.display_Petrol();
    cout << endl;

    return 0;
}
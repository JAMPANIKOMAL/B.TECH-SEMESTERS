//Pointer derived class

#include <iostream>
using namespace std;

class Base
{
    public:
        void showBase()
        {
            cout << "Base" << endl;
        }
};

class Derived1 : public Base
{
    public:
        void showDerived()
        {
            cout << "Derived1" << endl;
        }
};

int main()
{
    cout << endl;

    Derived1 d1;
    Base * bptr;
    bptr = &d1;
    bptr -> showBase();
    //bptr -> showDerived(); //erroe
    ((Derived1 * )bptr) -> showDerived();

    cout << endl;

    return 0;
}
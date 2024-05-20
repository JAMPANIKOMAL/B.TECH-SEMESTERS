//Virtual Functions

#include<iostream>
using namespace std;

class base
{
    public:
        virtual void show()
        {
            cout << "base" << endl;
        }
};

class derived1 : public base
{
    public:
        void show()
        {
            cout << "derived1" << endl;
        }
};

class derived2 : public base
{
    public:
        void show()
        {
            cout << "derived2" << endl;
        }
};

int main()
{
    cout << endl;
    derived1 d1;
    derived2 d2;
    base * bptr;

    bptr = &d1;
    bptr -> show();
    cout << endl;

    bptr = &d2;
    bptr -> show();
    cout << endl;

    return 0;
}

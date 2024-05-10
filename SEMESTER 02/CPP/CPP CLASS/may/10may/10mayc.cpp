//4. Hierarchieal Inheritance
//Multiple Derived Class One Base Class

#include <iostream>
using namespace std;

class Animal
{
    public:
        void display1()
        {
            cout << "Animal Class" << endl;
        }
};

class Elephant : public Animal
{
    public:
        void display2()
        {
            cout << "Elephant Class" << endl;
        }
};

class Horse : public Animal
{
    public:
        void display3()
        {
            cout << "Horse Class" << endl;
        }
};

class Cow : public Animal
{
    public:
        void display4()
        {
            cout << "Cow Class" << endl;
        }
};

int main()
{
    cout << endl;

    Animal a;
    Elephant e;
    Horse h;
    Cow c;

    a.display1();
    cout << endl;

    e.display2();
    e.display1();
    cout << endl;

    h.display3();
    h.display1();
    cout << endl;

    c.display4();
    c.display1();
    cout << endl;

    return 0;
}


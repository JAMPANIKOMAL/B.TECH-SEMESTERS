//INHERITANCE

//BASE CLASS, SUPER CLASS, PARENT CLASS
//DERIVED CLASS, SUB CLASS, CHILD CLASS

//1. Single Inheritance

#include <iostream>
using namespace std;

class Animal
{
    private:
        int legs = 4;
    
    public:
        void display1()
        {
            cout << "Legs = " << legs << endl;
        }
};

class Dog : public Animal
{
    private:
        bool tail = true;

    public:
        void display2()
        {
            cout << "Tail = " << tail << endl;
        }
};

int main()
{
    cout << endl;

    Animal a1;
    Dog d1;

    d1.display1();
    d1.display2();

    cout << endl;
    
    return 0;
}
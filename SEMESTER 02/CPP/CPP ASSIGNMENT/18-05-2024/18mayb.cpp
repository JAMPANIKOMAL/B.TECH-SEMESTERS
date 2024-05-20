#include <iostream>
using namespace std;

class Animal 
{
    public:
        string name = "Animal";
        virtual void print()
        {
            cout << name << endl;
        }; 
};

class Dog : public Animal 
{
    public:
        string name = "Dog";
        void print()
        {
            cout << name << endl;
        }
};

int main()
{
    Animal * a1;
    Dog d1;
    a1 = &d1;
    a1 -> print();
}
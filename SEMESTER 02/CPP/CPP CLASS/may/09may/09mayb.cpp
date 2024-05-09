//1. Single Inheritance

#include <iostream>
using namespace std;

class Animal
{
    private:
        int legs = 4;
    
    public:
        void display_Animal()
        {
            cout << "Legs = " << legs << endl;
        }
};

class Dog : public Animal
{
    private:
        bool tail = true;

    public:
        void display_Dog()
        {
            display_Animal();
            cout << "Tail = " << tail << endl;
        }
};

int main()
{
    cout << endl;

    Dog d1;
    d1.display_Dog();

    cout << endl;
    
    return 0;
}
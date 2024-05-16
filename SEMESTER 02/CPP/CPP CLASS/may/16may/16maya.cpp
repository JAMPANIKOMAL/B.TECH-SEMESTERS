//Derived Class Constructor
//Cannot change or overcome.

#include <iostream>
using namespace std;

class base
{
    private:
        int x;
    
    public:
        base()
        {
            cout << "base Default Constructor." << endl;
        }
};

class derived : public base
{
    private:
        int y;
    
    public:
        derived()
        {
            cout << "derived Default Constructor." << endl;
        }

        derived(int x)
        {
            cout << "derived Parameterized Constructor." << endl;
        }
};

int main()
{
    cout << endl;

    base b;
    cout << endl;
    
    derived d1;
    cout << endl;
    derived d2(3);

    cout << endl;

    return 0;
}
//Write a C++ program to demonstrate the usage of a constructor and destructor in a class.

#include <iostream>
using namespace std;

class demo
{
    public:
        demo()
        {
            cout << "Constructor!" << endl;
        }

        ~demo()
        {
            cout << "Deconstructor!" << endl << endl;
        }
};

int main()
{
    cout << endl;

    demo d1;

    cout << endl;

    return 0;
}
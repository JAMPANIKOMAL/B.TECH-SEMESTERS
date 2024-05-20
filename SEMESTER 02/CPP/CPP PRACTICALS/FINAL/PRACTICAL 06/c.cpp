//Write a C++ program to demonstrate parameterized Constructor.

#include <iostream>
using namespace std;

class demo
{
    private:
        int a;
    
    public:
        demo()
        {
            cout << "Default Constructor!" << endl;
        }

        demo(int b)
        {
            a = b;
            cout << "Parametrized Constructor!" << endl;
        }
};

int main()
{
    cout << endl;

    demo d1;
    demo d2(3);

    cout << endl;

    return 0;
}
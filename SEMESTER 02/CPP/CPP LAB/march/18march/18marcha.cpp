//CLASS AND OBJECT.

#include <iostream>
using namespace std;

class additionof2
{
    public:
        int a, b, sum;
        void input()
        {
            cout << "\nEnter your first number: ";
            cin >> a;
            cout << "Enter your second number: ";
            cin >> b;
        }
        void calculate()
        {
            sum = a +b;
        }
        void output()
        {
            cout << "\n" << a << " + " << b << " = " << sum << endl << endl;
        }
};

int main()
{
    additionof2 s1;
    s1.input();
    s1.calculate();
    s1.output();

    return 0;
}
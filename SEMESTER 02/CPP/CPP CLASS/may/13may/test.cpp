// Write a program for multiple inheritance
//TEJA'S CODE

#include <iostream>
using namespace std;

class add
{
    public:
        int n, m;

        void number()
        {
            n = 0;
            m = 0;
        }

        void getnumber(int x, int y)
        {
            n = x;
            m = y;
        }

        void display1()
        {
            cout << "Entered Numbers are " << n << " and " << m << endl;
        }
};

class sum : virtual public add
{
    public:
        void display2()
        {
            cout << "Sum= " << n + m;
        }
};

class both : virtual public add, public sum
{
    public:
        void display3()
        {
            cout << "For Multiple Inheritance:" << endl;
        }
};

int main()
{
    int x = 0, y = 0;
    cout << "Enter num1: ";
    cin >> x;
    cout << "Enter num2: ";
    cin >> y;

    add r;
    sum s;
    both b;

    r.getnumber(x, y);
    r.display1();

    s.getnumber(x, y);
    s.display1();
    s.display2();

    b.display3();
    b.getnumber(x, y);
    b.display1();
    b.display2();

    return 0;
}
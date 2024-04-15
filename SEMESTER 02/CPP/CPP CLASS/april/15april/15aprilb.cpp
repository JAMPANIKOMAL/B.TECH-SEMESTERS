//Invoke Friend Function in Operator ovrloading.

#include <iostream>
using namespace std;

class complex 
{
    private:
        int real, imag;
    public:
        complex()
        {
            real = 0;
            imag = 0;
        }

        complex(int x, int y)
        {
            real = x;
            imag = y;
        }

        void disp()
        {
            cout << endl << "Real Value = " << real;
            cout << endl << "Imaginary Value = " << imag;
        }

        friend complex operator + (complex c1, complex c2);
};

complex operator + (complex c1, complex c2)
{
    complex tmp;
    tmp.real = c1.real + c2.real;
    tmp.imag = c1.imag + c2.imag;
    return tmp;
}

int main()
{
    complex c1(4, 5), c2(7, 9);
    complex c3;

    c3 = c1 + c2;

    c1.disp();
    cout << endl;

    c2.disp();
    cout << endl;
    
    c3.disp();
    cout << endl << endl;

    return 0;
}
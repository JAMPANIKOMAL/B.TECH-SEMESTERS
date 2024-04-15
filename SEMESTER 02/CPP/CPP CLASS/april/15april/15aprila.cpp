//Operator ovrloading.

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

        complex operator + (complex);
};

complex complex :: operator + (complex c)
{
    complex tmp;
    tmp.real = real + c.real;
    tmp.imag = imag + c.imag;
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
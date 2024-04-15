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

        friend bool operator == (complex c1, complex c2);
};

bool operator == (complex c1, complex c2)
{
    if(c1.real == c2.real && c1.imag == c2.imag)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    cout << endl;
    complex c1(4, 5), c2(9, 11);
    complex c3;

    if(c1 == c2)
    {
        cout << "Objects are equal." << endl;
    }
    else
    {
        cout << "Objects are not equal." << endl;
    }

    c1.disp();
    cout << endl;

    c2.disp();
    cout << endl;
    
    c3.disp();
    cout << endl << endl;

    return 0;
}
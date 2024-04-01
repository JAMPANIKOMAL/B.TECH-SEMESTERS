//PASSING OBJECT AS AN ARGUMENT.

#include<iostream>
using namespace std;

class Complex
{
    private:
        int real, imaginary;

    public:
        void getdata()
        {
            cout << "Enter Real Part: ";
            cin >> real;
            cout << "Enter Imaginary Part: ";
            cin >> imaginary;
        }

        void printdata()
        {
            cout << "Complex Number: " << real << " + " << imaginary << "i";
        }

        void addComplexNumbers(Complex x, Complex y)
        {
            real = x.real + y.real;
            imaginary = x.imaginary + y.imaginary;
        }
};

int main()
{
    Complex c1, c2, c3;

    cout << endl << "Enter c1: " << endl;
    c1.getdata();
    c1.printdata();
    cout << endl;

    cout << endl << "Enter c2: " << endl;
    c2.getdata();
    c2.printdata();
    cout << endl;

    c3.addComplexNumbers(c1, c2);

    cout << endl << "c3: " << endl;
    c3.printdata();
    cout << endl << endl;

    return 0;
}
//Write a C++ program to convert Celsius to Fahrenheit and Fahrenheit to Celsius.

#include<iostream>
using namespace std;

float ctof(float c);
float ftoc(float f);

int main()
{
    cout << endl;
    float f, c;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> f;
    cout << f <<"f = " << ftoc(f) << "c " << endl;

    cout << "Enter temperature in Celcius: ";
    cin >> c;
    cout << c <<"c = " << ctof(c) << "f " << endl;
    cout << endl;

    return 0;
}

float ctof(float c)
{
    return (c * (9 / 5) + 32);
}

float ftoc(float f)
{
    return ((f - 32) * (5 / 9));
}
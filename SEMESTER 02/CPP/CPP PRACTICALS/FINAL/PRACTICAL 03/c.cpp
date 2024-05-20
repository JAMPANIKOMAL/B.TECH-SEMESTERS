//Write a C++ program to check whether a number is odd or even.

#include <iostream>
using namespace std;

int main()
{
    cout << endl;
    int a;
    cout << "Enter your number: ";
    cin >> a;

    if(a % 2 == 0)
    {
        cout << a << " is an even number." << endl;
    }
    else
    {
        cout << a << " is an odd number." << endl;
    }

    cout << endl;

    return 0;
}
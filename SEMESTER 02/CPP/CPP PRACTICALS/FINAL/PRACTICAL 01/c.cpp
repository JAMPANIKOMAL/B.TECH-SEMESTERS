//Write a C++ program to print a square pattern.

#include <iostream>
using namespace std;

int main ()
{
    int n;
    cout << endl;
    cout << "Enter the size of square: ";
    cin >> n;
    cout << endl;
    
    for (int i=0; i<n; i++)
    {
        for (int k=0; k<n; k++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    cout << endl;
    
    return 0;
}

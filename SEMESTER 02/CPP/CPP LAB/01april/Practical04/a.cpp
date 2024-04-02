//Write a C++ program to enter an element in an array and display it.

#include <iostream>
using namespace std;

int main()
{
    cout << endl;
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    int a[size];
    cout << endl;

    //SCANNING VALUES OF ARRAY.
    cout << "Enter the elements of your array: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter the value of Element " << i << ":";
        cin >> a[i]; 
    }

    //PRINTING ARRAY.
    cout << endl << "Your array is: ";
    cout << "{";
    for(int i = 0; i < size-1; i++)
    {
        cout << a[i] << ", ";
    }
    for(int i = size-1; i < size; i++)
    {
        cout << a[i];
    }
    cout << "}" << endl;
    cout << endl;

    return 0;
}
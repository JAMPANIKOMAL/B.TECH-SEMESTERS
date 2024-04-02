//Write a C++ program to check palindrome through string.
//NOT WORKING

#include<iostream>
using namespace std;

int main()
{
    cout << endl;
    string a;
    cout << "Enter your string: ";
    cin >> a;

    string b;
    int len = a.length();
    for(int i = 0; i < len; i++)
    {
        b[len-i-1] = a[i];
    }

    cout << b;

    if(b == a)
    {
        cout << endl << "Entered string is a Palindrome." << endl;
    }
    else
    {
        cout << endl << "Entered string is not a Palindrome." << endl;
    }
    cout << endl;

    return 0;
}

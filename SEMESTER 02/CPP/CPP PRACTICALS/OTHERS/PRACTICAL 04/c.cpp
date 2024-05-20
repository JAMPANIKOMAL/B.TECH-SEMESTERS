//Write a C++ program to check palindrome through string.

#include<iostream>
using namespace std;

void isstring(string a);

int main()
{
    cout << endl;
    string a;
    cout << "Enter your string: ";
    cin >> a;
    int b;
    isstring(a);
    cout << endl;

    return 0;
}

void isstring(string a)
{
    string b;
    b = a;
    int leng = a.length();

    for(int i = 0; i < leng; i++)
    {
        b[leng - i - 1] = a[i];
    }

    if(b == a)
    {
        cout << "Entered string is a Palindrome." << endl;
    }
    else
    {
        cout << "Entered string is not a Palindrome." << endl;
    }
}
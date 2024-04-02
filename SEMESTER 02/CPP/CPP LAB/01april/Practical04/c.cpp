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
    int size = a.length(); 

    int flag = 1;
    
    if(size % 2 == 0)
    {
        for(int i = 0; i < size/2; i++)
        {
            for(int j = size-1; j >= size/2; j--)
            {
                if(a[i] != a[j])
                {
                    flag = 0;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < size/2; i++)
        {
            for(int j = size-1; j > size/2; j--)
            {
                if(a[i] != a[j])
                {
                    flag = 0;
                }
            }
        }
    }
        

    if(flag == 1)
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

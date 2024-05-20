//Function overloading between integer and string type.

#include <iostream>
using namespace std;

void demo(string d)
{
    cout << d << endl;
}

void demo(int i)
{
    cout << i << endl;
}

int main()
{
    string a;
    cout << "Enter your Name: "; 
    getline(cin, a);
    demo(a);

    int b;
    cout << "Enter your Enrollment number: "; 
    cin >> b;
    demo(b);

    return 0;
}
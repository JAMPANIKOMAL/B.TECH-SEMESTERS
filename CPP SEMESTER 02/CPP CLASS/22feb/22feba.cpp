// CALL BY VALUE.
#include <iostream>
using namespace std;
void cbv(int a, int b);
int main()
{
    cout << endl;
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Before swapping a=" << a << ", b=" << b << "." << endl;
    cbv(a, b);
    cout << "After swapping using call by value a=" << a << ", b=" << b << "." << endl;
    cout << endl;

    return 0;
}

void cbv(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    // cout << "After swapping call by value a=%d, b=%d.", a, b;
}
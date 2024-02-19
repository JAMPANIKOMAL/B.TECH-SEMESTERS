//PROGRAM TO PRINT RIGHT ISCOSCELES TRIANGLE RIGHT ANGLED AT LEFT HAND SIDE PATTERN.
#include <iostream>
using namespace std;
int main ()
{
    cout << endl;
    int n;
    cout << "Enter the size of triangle: ";
    cin >> n;
    cout << endl;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
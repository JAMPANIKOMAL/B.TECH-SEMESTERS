//PROGRAM TO PRINT SQUARE PATTERN.
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
        if (i==0 || i==n-1)
            {
                for (int k=0; k<n; k++)
                {
                    cout << "* ";
                }
                cout << "\n";
            }
        else
        {
            for (int j=0; j<n; j++)
            {
                if (j==0 || j==n-1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << "\n";
        }
    }
    cout << endl;
    
    return 0;
}
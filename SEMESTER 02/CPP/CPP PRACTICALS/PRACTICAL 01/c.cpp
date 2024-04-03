//PROGRAM TO PRINT rectangle PATTERN.
#include <iostream>
using namespace std;
int main ()
{
    cout << endl;
    int r, c;
    cout << "Enter number of rows of rectangle: ";
    cin >> r;
    cout << "Enter number of columns of rectangle: ";
    cin >> c;
    cout << endl;

    for (int i=0; i<r; i++)
    {
        if (i==0 || i==r-1)
            {
                for (int k=0; k<c; k++)
                {
                    cout << "* ";
                }
                cout << "\n";
            }
        else
        {
            for (int j=0; j<c; j++)
            {
                if (j==0 || j==c-1)
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
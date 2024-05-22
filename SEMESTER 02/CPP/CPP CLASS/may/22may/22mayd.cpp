//Catch All

#include <iostream>
using namespace std;

void divide(double x, double y);

int main()
{
    cout << endl;
    
    try
    {
        divide(3.0, 4.0);
        divide(3.0, 0.0);
    }

    catch(double)
    {
        cout << endl << "Exception in main function.";
    }

    cout << endl << endl;

    return 0;
}

void divide(double x, double y)
{
    try
    {
        if (y == 0)
        {
            throw y;
        }
        else
        {
            cout << "Division = " << x / y;
        }
    }

    catch(double)
    {
        cout << endl << "Exception inside function.";
        throw;
    }
}
//Exception Handling.

#include <iostream>
using namespace std;

int main()
{
    cout << endl;

    int a, b, c;
    cout << "Enter two values: ";
    cin >> a >> b;

    try
    {
        if(b != 0)
        {
            c = a / b;
            cout << "Answer: " << c;
        }
        else
        {
            throw(b);
        }
    }
    catch(int x)
    {
        cout << "Ecxeption caught: Divide by zero" ;
    }

    cout << endl << endl;;

    return 0;
}
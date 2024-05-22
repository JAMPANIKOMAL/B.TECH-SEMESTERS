//User defined exception.
//NOT WORKING

#include <iostream>
#include <exception>
using namespace std;

class myexception : public exception
{
    public:
        const string what() const throw()
        {
            return "Attempted to divide by zero!";
        }
};

int main()
{
    cout << endl;

    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    
    try
    {
        if(y == 0)
        {
            myexception z;
            throw z;
        }
        else
        {
            cout << "x / y = " << x / y << endl;
        }
    }

    catch(exception& e)
    {
        cout << e.what();
    }

    cout << endl;

    return 0;
}
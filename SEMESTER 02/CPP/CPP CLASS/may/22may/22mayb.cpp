//Multiple Catch

#include <iostream>
using namespace std;

void test(int x);

int main()
{
    test(1);
    test(0);
    test(-1);

    cout << endl << endl;

    return 0;
}

void test(int x)
{
    try
    {
        if (x == 1)
        {
            throw x;
        }
        else if( x == 0)
        {
            throw 'x';
        }
        else if(x == -1)
        {
            throw 5.14;
        }
    }

    catch(int i)
    {
        cout << endl << "Caught an integer.";
    }

    catch(char ch)
    {
        cout << endl << "Caught a character.";
    }

    catch(double d)
    {
        cout << endl << "Caught a double.";
    }
}
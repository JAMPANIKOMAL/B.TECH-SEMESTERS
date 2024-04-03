#include <iostream>
using namespace std;
int m = 20;
int main()
{
    // :: Scope resolution operator.
    int m = 10;
    cout << m << endl;
    cout << ::m;

    return 0;
}
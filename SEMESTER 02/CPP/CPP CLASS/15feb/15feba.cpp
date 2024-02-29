#include <iostream>
using namespace std;
int main()
{
    int x, y;
    x=5;
    y=++x*++x;
    cout << x << y;
    x=5;
    y=x++*++x;
    cout<<x<<y;
    //Different answer in different compilers. 742725 or 749735. 
    //May be 749735 because the last value of incremented x is used in equation.
    
    return 0;
}

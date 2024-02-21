#include <iostream>
using namespace std;
//STATIC SCOPING.
int x=10;
int f()
{
    return x;
}
int g()
{
    int x=20;
    return f();
}
int main ()
{
    cout << g();

    return 0;
}
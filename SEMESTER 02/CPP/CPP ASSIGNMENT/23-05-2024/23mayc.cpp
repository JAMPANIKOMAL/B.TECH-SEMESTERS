//Function Overloading and Default Arguments: Write a C++ program that includes a function called add that is overloaded three times:

#include <iostream>
using namespace std;

int add(int a, int b);
int add(int a, int b, int c);
double add(double a, double b);

int main()
{
    int a, b, c = 10;
    cin >> a >> b;
    cout << add(a, b);
    cout << add(a, b, c);

    double d, e;
    cin >> d >> e;
    cout << add(d, e);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

double add(double a, double b)
{
    return a + b;
}
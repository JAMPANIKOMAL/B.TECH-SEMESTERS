//Function Overloading and Default Arguments: Write a C++ program that includes a function called add that is overloaded three times:

#include <iostream>
using namespace std;

class over
{
    public:
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
};

int main()
{
    over o;
    cout << o.add(3, 4);
    cout << o.add(3, 4, 5);
    cout << o.add(3.4, 4.3);
    return 0;
}


//Copy constructor.
//Complete this.

#include<iostream>
using namespace std;

class demo
{
    private:
        int m, n;
    public:
        demo(int x, int y)
        {
            m = x;
            n = y;
            cout << "Parameterized constructor.";
        }
        
        demo(demo &x)
};


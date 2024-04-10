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
        {
            m = x.m;
            n = x.n;
            cout << "Copy constructor.";
        }
};

int main()
{
    demo obj1(5, 6);
    demo obj2(obj1);
    obj2 = obj1;
}


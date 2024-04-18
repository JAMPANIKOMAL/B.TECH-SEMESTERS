//Overloading Prefix and Postfix operator.

#include <iostream>
using namespace std;

class demo
{
    private:
        int m;
    public:
        demo()
        {
            m = 0;
        }

        demo(int x)
        {
            m = x;
        }

        void operator ++ ()
        {
            ++m;
            cout << "Pre Increment = " << m;
        }

        void operator ++ (int)   //Using int because we are passing explicitly as data is written first not sign.
        {
            m++;
            cout << "Post Increment = " << m;
        }
};

int main()
{
    demo d1(3);
    cout << endl;
    ++d1;

    cout << endl << endl;
    d1++;

    cout << endl << endl;

    return 0;
}
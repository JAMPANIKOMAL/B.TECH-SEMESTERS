//Overloading Unary Operator -- data member value.
//Postfix.

#include <iostream>
using namespace std;

class num
{
    private:
        int a;
        int b;
    public:
        num()
        {
            a = b = 0;
        }

        num(int a1, int b1)
        {
            a = a1;
            b = b1;
        }

        void dispalydata()
        {
            cout << "a: " << a << endl;
            cout << "b: " << b << endl;
        }
        void operator -- (int);
};

void num :: operator -- (int)    //Passing object explicitly using int because data is written first not sign.
{
    a--;
    b--;
}

int main()
{
    num na(3, -4);
    cout << endl << "Before using - overloading operator." << endl;
    na.dispalydata();
    
    na--;
    cout << endl << "After using - overloading operator." << endl;
    na.dispalydata();
    cout << endl;

    return 0;
}
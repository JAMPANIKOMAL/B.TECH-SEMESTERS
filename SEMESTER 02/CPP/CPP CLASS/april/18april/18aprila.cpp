//Overloading Unary Operator - negative value of the data member.

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
        friend num operator - (num n1);
};

num operator - (num n1)    //Passing object explicitly.
{
    n1.a = -1*(n1.a);
    n1.b = -1*(n1.b);
    return n1;
}

int main()
{
    cout << endl;
    num na(3, -4), nb;
    cout << endl;
    na.dispalydata();

    nb = -na;
    nb.dispalydata();
    cout << endl << endl;

    return 0;
}
//Friend Function.

#include<iostream>
using namespace std;

class Numbers
{
    private:
        int n1, n2;
    public:
        void setdata(int a, int b);
        friend int add(Numbers n);
};

void Numbers :: setdata(int a, int b)      //Another type of syntax for class function declaration.
{
    n1 = a;
    n2 = b;
}

int add(Numbers N)
{
    return (N.n1 + N.n2);
}

int main()
{
    cout << endl;
    Numbers N1;
    N1.setdata(3, 4);
    cout << "Sum = " << add(N1) << endl << endl;

    return 0;
}
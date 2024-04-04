//Friend to another class.

#include<iostream>
using namespace std;

class A;
class B;  //Forward Declaration.

class A
{
    private:
        int a1;
    public:
        void setdata()
        {
            a1 = 3;
        }
        friend void add(A, B);
};

class B
{
    private:
        int b1;
    public:
        void setdata()
        {
            b1 = 4;
        }
        friend void add(A, B);
};

void add(A A1, B B1)
{
    int sum = A1.a1 + B1.b1;
    cout << "Sum = " << sum;
}

int main()
{
    cout << endl;
    A A1;
    B B1;
    A1.setdata();
    B1.setdata();
    add(A1, B1);
    cout << endl << endl;

    return 0;
}

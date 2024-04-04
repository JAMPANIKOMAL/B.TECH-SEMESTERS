//Friend Function.

#include<iostream>
using namespace std;

class Box
{
    private:
        double width;
        friend void printwidth(Box);  //Can declare Friend Function in private too.
    public:
        void setwidth(double a);
};

void Box :: setwidth(double a)
{
    width = a;
}

void printwidth(Box B)
{
    cout << "Width of box: " << B.width;
}

int main()
{
    cout << endl;
    Box B1;
    B1.setwidth(3.0);
    printwidth(B1);
    cout << endl << endl;

    return 0;
}
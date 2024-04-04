//Write a cpp program to find area of triangle and print it using Friend Function.

//Friend Function.

#include<iostream>
using namespace std;

class Triangle
{
    private:
        int base, height;
        friend void printarea(Triangle);
    public:
        void setdata(int base, int height);
};

void Triangle :: setdata(int base1, int height1)
{
    base = base1;
    height = height1;
}

void printarea(Triangle T)
{
    float area = T.base * T.height * 0.5;
    cout << "Area of Triangle: " << area;
}

int main()
{
    cout << endl;
    Triangle T1;
    T1.setdata(3, 4);
    printarea(T1);
    cout << endl << endl;

    return 0;
}
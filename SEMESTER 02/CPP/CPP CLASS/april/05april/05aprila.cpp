//Write the program to demonstrate the Friend Function to find area of rectangle and square.
//We also used overloading concept here.

#include<iostream>
using namespace std;

class Square
{
    private:
        int side;
    public:
        void setdata(int side1)
        {
            side = side1;
        }
        friend void printarea(Square);
};

class Rectangle
{
    private:
        int length, breadth;
    public:
        void setdata(int length1, int breadth1)
        {
            length = length1;
            breadth = breadth1;
        }
        friend void printarea(Rectangle);
};

void printarea(Square S)
{
    int area = S.side * S.side;
    cout << "Area of Square = " << area;
}

void printarea(Rectangle R)
{
    int area = R.length * R.breadth;
    cout << "Area of Rectangle = " << area;
}

int main()
{
    cout << endl;
    Square S1;
    S1.setdata(3);
    Rectangle R1;
    R1.setdata(3, 4);
    printarea(S1);
    cout << endl;
    printarea(R1);
    cout << endl << endl;

    return 0;
}
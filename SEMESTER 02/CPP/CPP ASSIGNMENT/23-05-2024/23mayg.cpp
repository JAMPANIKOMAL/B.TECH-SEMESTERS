//Create a base class Shape with a function area() that returns the area of the shape. Derive two classes from Shape: Circle and Square. Override the area() function in both derived classes to calculate the area specific to each shape. Demonstrate the concept of hierarchical inheritance by creating objects of Circle and Square and calling their area() functions.

#include <iostream>
using namespace std;

class Shape
{
    public:
        int x = 3;
        int area()
        {
            cout << "Shape Area: ";
            return 0;
        }
};

class Circle : public Shape
{
    public:
        float area()
        {
            return 3.14 * x * x;
        }
};

class Square : public Shape
{
    public:
        int area()
        {
            return x * x;
        }
};

int main()
{
    Circle C1;
    cout << C1.area() << endl;

    Square S1;
    cout << S1.area() << endl;

    return 0;
}
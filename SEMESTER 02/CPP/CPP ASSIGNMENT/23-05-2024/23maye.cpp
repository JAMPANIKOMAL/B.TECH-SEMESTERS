//Define a class Rectangle with private attributes length and width. Write a friend function area that calculates the area of the rectangle. Demonstrate how the friend function can access the private members of the Rectangle class.

#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int length;
        int width;

    public:
        Rectangle(){}
        Rectangle(int l, int w){length = l; width = w;}
        friend void calculate_area(Rectangle R);
};

void calculate_area(Rectangle R)
{
    cout << "Area = " << R.length * R.width;
}

int main()
{
    Rectangle R1(3, 4);
    calculate_area(R1);
    return 0;
}
//CLASS ARRAYS.

#include<iostream>
using namespace std;

class Rectangle 
{
    private: 
        double length;
        double width;
    public:
        Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
        void setdimensions(double l, double w)
        {
            length = l;
            width = w;
        }
        double area() const   //const uses will be known afterwards.
        {
            return length * width;
        }
};

int main()
{
    cout << endl;
    const int size = 3;
    Rectangle rectangles[size];
    rectangles[0].setdimensions(3.0, 4.0);
    rectangles[1].setdimensions(3.3, 4.4);
    rectangles[2].setdimensions(4.0, 3.0);

    for(int i = 0; i < size; ++i)  
    {
        cout << "Rectangle " << i + 1 << " Area: " << rectangles[i].area() << endl;
    }
    cout << endl;

    return 0;
}
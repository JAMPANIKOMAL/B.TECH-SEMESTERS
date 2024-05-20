//Pure Virtual Function

#include <iostream>
using namespace std;

class shape
{
    protected:
        float x;
    
    public:
        void getdata()
        {
            cin >> x;
        }

        virtual float calculatearea() = 0;
        //virtual float calculatarea() {};
};

class square : public shape
{
    public:
        float calculatearea()
        {
            return x * x;
        }
};

class circle : public shape
{
    public:
        float calculatearea()
        {
            return 3.14 * x * x;
        }
};

int main()
{
    cout << endl;
    square s;
    circle c;

    cout << "Enter the length to calculate the area of Square: ";
    s.getdata();
    cout << "Area of Square: " << s.calculatearea() << endl;
    cout << endl;

    cout << "Enter the radius to calculate the area of Circle: ";
    c.getdata();
    cout << "Area of Circle: " << c.calculatearea() << endl;

    cout << endl;

    return 0;
}


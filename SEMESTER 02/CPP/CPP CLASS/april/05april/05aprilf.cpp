//Create a class Distance having data members feet and inch. Create parameterized constructor to initialise members feet and inch.

#include<iostream>
using namespace std;

class Distance
{
    private:
        int feet, inch;
    public:
        Distance(float feet1, float inch1)
        {
            feet = feet1;
            inch = inch1;
        }
        void display()
        {
            cout << "Feet = " << feet;
            cout << endl << "Inch = " << inch ;
        }
};

int main()
{
    cout << endl;
    Distance D1(3, 4);
    D1.display();
    cout << endl << endl;
    
    Distance D2(3, 4);
    D2.display();
    cout << endl << endl;

    return 0;
}
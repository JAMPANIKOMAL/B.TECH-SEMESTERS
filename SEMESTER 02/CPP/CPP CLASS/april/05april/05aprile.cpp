//Parameterized Constructor.

#include<iostream>
using namespace std;

class Area
{
    private:
        int length, breadth;
    public:
        Area(int length1, int breadth1)
        {
            length = length1;
            breadth = breadth1;
        }
        void display()
        {
            cout << "Area = " << length * breadth;
        }
};

int main()
{
    cout << endl;
    Area A1(3, 4);
    A1.display();
    cout << endl;
    
    Area A2(3, 4);
    A2.display();
    cout << endl << endl;

    return 0;
}
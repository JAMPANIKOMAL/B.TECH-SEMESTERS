//Default constructor.

#include<iostream>
using namespace std;

class Area
{
    private:
        int length, breadth;
    public:
        Area()
        {
            length = 3;
            breadth = 4;
        }
        void Caluclate()
        {
            cout << "Area = " << length * breadth;
        }
};

int main()
{
    cout << endl;
    Area A1;
    A1.Caluclate();
    cout << endl;
    Area A2;
    A2.Caluclate();
    cout << endl << endl;

    return 0;
}
//Function Overriding

#include <iostream>
using namespace std;

class ABC
{
    public:
        void dispaly()
        {
            cout << "This is parent class.";
        }
};

class XYZ : public ABC
{
    public:
        void dispaly()
        {
            cout << "This is child class.";
        }
};

int main()
{
    cout << endl;
    XYZ x;
    x.dispaly();
    cout << endl;
    x.ABC::dispaly();
    cout << endl << endl;

    return 0;
}
//Nesting member function.

#include<iostream>
using namespace std;

class rectangle
{
    private:
        int w, h;
    public:
        void setvalue(int w1, int h1)
        {
            w = w1;
            h = h1;
            displayvalue();
        }
        void displayvalue()
        {
            cout << "Width = " << w << endl;
            cout << "Height = " << h;
        }
};

int main()
{
    cout << endl;
    rectangle r1;
    //r1.displayvalue();        //Prints garbage value here.
    r1.setvalue(3, 4);
    cout << endl << "---------" << endl;
    r1.displayvalue();
    cout << endl << endl;

    return 0;
}
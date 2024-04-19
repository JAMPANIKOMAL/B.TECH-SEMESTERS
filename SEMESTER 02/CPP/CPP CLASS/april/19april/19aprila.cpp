//Type Conversion
//01. Basic to Class type conversion using constructor.

#include <iostream>
using namespace std;

class sample
{
    private:
        int a;
        float b;
    public:
        sample() {}

        sample(int x)
        {
            a = x;
        }

        sample(float y)
        {
            b = y;
        }

        void display()
        {
            cout << "The value of a = " << a << endl;
            cout << "The value of b = " << b;  //Not displaying b as it is not initialised or value inputted.
        }
};

int main()
{
    cout << endl;

    int m = 10;
    sample s;

    s = m;   //Basic to class read from left to right.
    s.display();

    cout << endl << endl;

    return 0;
}
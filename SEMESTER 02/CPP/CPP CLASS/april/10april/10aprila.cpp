/*Create a class Rectangle having data members' length and width. Deonstrate default, parameteized and copy constructor t initialize members and also demonstrate constructor overloading.*/

#include<iostream>
using namespace std;

class Rectangle
{
    private:
        int length, width;
    public:
        Rectangle()
        {
            length = 4;
            width = 3;            //Hardcoding values can take input from user too.
            cout << endl << "Default constructor: ";
            cout << endl <<  "Length: " << length;
            cout << endl << "Width: " << width;

        }
        Rectangle(int length1, int width1)
        {
            length = length1;
            width = width1;
            cout << endl << "Parameterised constructor: ";
            cout << endl <<  "Length: " << length;
            cout << endl << "Width: " << width;
        }
        Rectangle(Rectangle &R)
        {
            length = R.length;
            width = R.width;
            cout << endl << "Copy constructor: ";
            cout << endl <<  "Length: " << length;
            cout << endl << "Width: " << width;
        }
};

int main()
{
    cout << endl;
    Rectangle R1;

    cout << endl;
    Rectangle R2(3, 4);

    cout << endl;
    Rectangle R3(R1);

    cout << endl << endl;

    return 0;
}
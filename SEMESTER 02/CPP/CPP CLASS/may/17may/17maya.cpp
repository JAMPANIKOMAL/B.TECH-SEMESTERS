//Polymorphism
//Pointer and objects.

#include <iostream>
using namespace std;

class ABC
{
    public:
        int a = 3;
};

int main()
{
    cout << endl;

    ABC A1;
    ABC *ptr;

    ptr = &A1;

    cout << A1.a << endl;
    cout << ptr -> a << endl;  //Accesing member with pointer.

    cout << endl;

    return 0;
}
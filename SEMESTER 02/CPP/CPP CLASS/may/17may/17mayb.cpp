//Polymorphism
//Pointer and objects.

#include <iostream>
using namespace std;

class demo
{
    private:
        int i;
    
    public:
        demo(int x)
        {
            i = x;
        }

        int getdata()
        {
            return i;
        }
};

int main()
{
    cout << endl;

    demo d1(55), *ptr;
    // demo *ptr;

    ptr = &d1;

    cout << ptr -> getdata() << endl;  

    cout << endl;

    return 0;
}
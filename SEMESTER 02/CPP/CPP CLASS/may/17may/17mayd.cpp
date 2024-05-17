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

    demo d1[3] = {55, 66, 77};
    demo *ptr = d1;   //Similar to *ptr = &d[0]

    for(int i = 0; i < 3; i++)
    {
        cout << (ptr + i) -> getdata() << endl;
        //ptr++;
    }

    cout << endl;

    return 0;
}
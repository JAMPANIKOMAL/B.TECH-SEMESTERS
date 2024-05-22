//Class template.
//Complete form ppt.

#include <iostream>
using namespace std;

template <class t1, class t2>

class sample
{
    private:
        t1 a;
        t2 b;

    public:
        sample(t1 x, t2 y)
        {
            a = x;
            b = y;
        }

        void display()
        {
            cout << endl << " a = " << "\tb = " << b;
        }
};

int main()
{


    return 0;
}
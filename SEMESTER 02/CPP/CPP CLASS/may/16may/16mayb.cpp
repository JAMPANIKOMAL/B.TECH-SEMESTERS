//Derived Class Constructor

#include <iostream>
using namespace std;

class base
{
    private:
        int x;
    
    public:
        base(int i)
        {
            x = i;
            cout << "x = " << x << endl;
        }
};

class derived : public base
{
    private:
        int y;
    
    public:
        derived(int i, int j) : base(j)
        {
            y = i;
            cout << "y = " << y << endl;
        }
};

int main()
{
    cout << endl;

    derived(3, 4);

    cout << endl;

    return 0;
}
//Write a C++ program that demonstrates the use of the this pointer.

#include <iostream>
using namespace std;

class sample
{
    private:
        int a;

    public:
        void input(int a)
        {
            this -> a = a;
        }

        void output()
        {
            cout << "a = " << a << endl;
        }
};

int main()
{
    cout << endl;

    sample s1;
    int a = 3;
    s1.input(a);
    s1.output();

    cout << endl;

    return 0;
}
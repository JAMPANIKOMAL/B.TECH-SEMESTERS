//this pointer

#include <iostream>
using namespace std;

class sample
{
    private:
        int a, b;  //instance variables

    public:
        void input(int a, int b)  //local variables.
        {
            this -> a = a + b;
            this -> b = a - b;
        }

        void output()
        {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }
};

int main()
{
    cout << endl;

    sample s1;
    int a = 3, b = 4;
    s1.input(a, b);
    s1.output();

    cout << endl;

    return 0;
}
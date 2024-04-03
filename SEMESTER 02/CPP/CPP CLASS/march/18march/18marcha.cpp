class test
{
    private:
        int data1;
        float data2;
    public:
        void function1()
        {
            data1 = 2;
        }
        float function2()
        {
            data2 = 3.5;
            return data2;
        }
};

#include<iostream>
using namespace std;

int main()
{
    test test1;
    test1.function1();
    float a = test1.function2();
    cout << a;

    return 0;
}
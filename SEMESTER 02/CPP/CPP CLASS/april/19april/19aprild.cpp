//Class to basic type conversion
//WAC++P (Write a c++ program) To find the length of an array (data member).

#include <iostream>
using namespace std;              

class Array
{
    private:
        int a1[5];

    public:
        Array() 
        {
            for (int i = 0; i < 5; i++)
            {
                a1[i] = i*2;
            }
        }

        operator int();
        operator long();
};

Array ::operator int()
{
    int length = 0;
    for (int i = 0; i < 5; i++)
    {
        length = length + 1;
    }
    return length;
}

Array :: operator long()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + a1[i];
    }
    return sum;
}

int main()
{
    cout << endl;

    Array a1;
    int len;
    long sum;
    len = a1;
    sum = a1;

    cout << "Length of array = " << len << endl;
    cout << "Sum of elements of array = " << sum;

    cout << endl << endl;

    return 0;
}
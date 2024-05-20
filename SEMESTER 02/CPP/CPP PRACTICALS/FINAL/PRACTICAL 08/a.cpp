//1. Write a Program to swap private data members of classes named as class_1, class_2 using friend function.
//2. Write a C++ program to demonstrate parameter passing mechanism using pass by address method

#include <iostream>
using namespace std;

class class_2;
class class_1
{
    private:
        int a;

    public:
        class_1(int a1) {a = a1;}

        void dispaly_class_1()
        {
            cout << "a = " << a << endl;
        }

        friend void swap(class_1 * c1, class_2 * c2);
};

class class_2
{
    private:
        int b;

    public:
        class_2(int b1) {b = b1;}

        void dispaly_class_2()
        {
            cout << "b = " << b << endl;
        }
        friend void swap(class_1 * c1, class_2 * c2);
};

void swap(class_1 * c1, class_2 * c2)
{
    int temp = c1 -> a;
    c1 -> a = c2 -> b;
    c2 -> b = temp;
}

int main()
{
    cout << endl;

    class_1 c1(3);
    class_2 c2(4);

    cout << "Before Swapping: " << endl;
    c1.dispaly_class_1();
    c2.dispaly_class_2();
    swap(&c1, &c2);
    cout << "After Swapping: " << endl;
    c1.dispaly_class_1();
    c2.dispaly_class_2();

    cout << endl;
    return 0;
}
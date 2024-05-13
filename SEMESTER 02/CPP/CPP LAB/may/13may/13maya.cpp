//FRIEND FUNCTION

#include <iostream>
using namespace std;

class Addition
{
    private:
        int a;
        int b;

    public:
        void setdata()
        {
            cout << "Enter Value of a: ";
            cin >> a;
            cout << "Enter Value of b: ";
            cin >> b;
        }

        void displaydata()
        {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl; 
        }

        void friend printsum(Addition A1);
};

void printsum(Addition A1)
{
    cout << "a + b = " << A1.a + A1.b << endl;
}

int main()
{
    cout << endl;

    Addition a1;

    a1.setdata();
    cout << endl;
    
    a1.displaydata();
    printsum(a1);

    cout << endl;

    return 0;
}
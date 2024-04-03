//Static Data Members

#include<iostream>
using namespace std;

class demo
{
    private:
        static int count;
    public:
        void getcount()
        {
            cout << "Count = " << ++count << endl;
        }
};

int demo :: count;

int main()
{
    cout << endl;
    demo d1, d2, d3;
    d1.getcount();
    d2.getcount();
    d3.getcount();
    cout << endl;

    return 0;
}

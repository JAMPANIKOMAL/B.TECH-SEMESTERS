//Static data member.

#include<iostream>
using namespace std;

class item
{
    private:
        int number;
        static int count;
    public:
        void getdata(int a)
        {
            number = a;
            //cout << number;
            count++;
        }
        void getcount()
        {
            cout << "Count = " << count << endl;
        }
};

int item :: count;

int main()
{
    cout << endl;
    item i1, i2, i3;

    i1.getdata(100);
    i1.getcount();

    i2.getdata(200);
    i2.getcount();

    i3.getdata(300);
    i3.getcount();

    cout << endl;

    return 0;
}
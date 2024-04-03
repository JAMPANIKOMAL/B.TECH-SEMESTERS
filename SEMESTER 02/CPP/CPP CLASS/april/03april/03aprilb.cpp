//Static Data members.

//Here static is declared to entire programm.
//Create in class so that it cannot be accessed form main.

#include<iostream>
using namespace std;

static int count;

class demo
{
    public:
        void getcount()
        {
            cout << "Count = " << ++count << endl;
        }
};

int main()
{
    cout << count << endl;
    demo d1, d2, d3;
    d1.getcount();
    d2.getcount();
    d3.getcount();

    return 0;
}

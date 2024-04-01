//PASSING OBJECT AS AN ARGUMENT.

#include<iostream>
using namespace std;

class Time
{
    private:
        int hours, minutes, seconds;

    public:
        void getTime()
        {
            cout << "Enter Hours: ";
            cin >> hours;
            cout << "Enter Minutes: ";
            cin >> minutes;
            cout << "Enter Seconds: ";
            cin >> seconds;
        }

        void printTime()
        {
            cout << "Hours: " << hours;
            cout << endl << "Minutes: " << minutes;
            cout << endl << "Seconds: " << seconds;
        }

        Time addTime(Time x, Time y)
        {
            Time z;
            z.hours = x.hours + y.hours;
            z.minutes = x.minutes + y.minutes;
            z.seconds = x.seconds + y.seconds;
            return z;
        }
};

int main()
{
    Time t1, t2, t3, t4;

    cout << endl << "Enter t1: " << endl;
    t1.getTime();
    cout << endl;
    t1.printTime();
    cout << endl;

    cout << endl << "Enter t2: " << endl;
    t2.getTime();
    cout << endl;
    t2.printTime();
    cout << endl;

    t4 = t3.addTime(t1, t2);

    cout << endl << "After adding time: " << endl;
    t4.printTime();
    cout << endl << endl;

    return 0;
}
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
            cout << "\nMinutes: " << minutes;
            cout << "\nSeconds: " << seconds;
        }

        void addTime(Time x, Time y)
        {
            hours = x.hours + y.hours;
            minutes = x.minutes + y.minutes;
            seconds = x.seconds + y.seconds;
        }
};

int main()
{
    Time t1, t2, t3;

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

    t3.addTime(t1, t2);

    cout << endl << "t3: " << endl;
    t3.printTime();
    cout << endl << endl;

    return 0;
}
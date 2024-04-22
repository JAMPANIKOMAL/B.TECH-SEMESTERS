//Class type to Class type

#include <iostream>
using namespace std;

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time(int h, int m)
        {
            hours = h;
            minutes = m;
        }

        int getminutes()
        {
            int total_minutes = (hours * 60) + minutes;
            return total_minutes;
        }

        void dispaly()
        {
            cout << "Hours: " << hours << endl;
            cout << "Minutes: " << minutes << endl;
        }
};

class Minute
{
    private:
        int min;
    public:
        Minute()
        {
            min = 0;
        }

        void operator = (Time T)
        {
            min = T.getminutes();
        }

        void display()
        {
            cout << endl << "Total Minutes: " << min << endl;
        }
};

int main()
{
    cout << endl;

    Time t1(2, 30);
    t1.dispaly();

    Minute m1;
    m1.display();

    m1 = t1;   //Conversion from Time to Minute.

    cout << endl;
    
    t1.dispaly();
    m1.display();

    cout << endl;

    return 0;
}
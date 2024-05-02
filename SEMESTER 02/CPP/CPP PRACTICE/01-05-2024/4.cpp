//CLASS TIME.

#include <iostream>
using namespace std;

class Time
{
    private:
	int Hours;
	int Minutes;
	int Seconds;

    public:
	Time() {}

        Time(int h, int m, int s)
	{
	    Hours = h;
	    Minutes = m;
	    Seconds = s;
	}

	/*Time(Time &T)
	{
	    Hours = T.Hours;
	    Minutes = T.Minutes;
	    Seconds = T.Seconds;
	}*/

	void displaydata()
	{
	    cout << "Hours: " << Hours << endl;
	    cout << "Minutes: " << Minutes << endl;
	    cout << "Seconds: " << Seconds << endl;
	}

	friend Time add_Time(Time T1, Time T2);
};

Time add_Time(Time T1, Time T2)
{
    Time T3;    
    T3.Hours = T1.Hours + T2.Hours;
    T3.Minutes = T1.Minutes + T2.Minutes;
    T3.Seconds = T1.Seconds + T2.Seconds;
    
    return T3;
}

int main()
{
    Time T1(1, 2, 3);
    Time T2(4, 5, 6); 
    Time T3;
    T1.displaydata();
    T2.displaydata();
    T3 = add_Time(T1, T2);
    T3.displaydata();

    return 0;
}
    
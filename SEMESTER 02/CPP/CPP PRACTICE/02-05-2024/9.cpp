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
        Minutes= m;
        Seconds = s;
	}

	void displaydata()
	{
	    cout << endl << "Hours: " << Hours << endl;
	    cout << "Minutes: " << Minutes << endl;
	    cout << "Seconds: " << Seconds << endl;
	}

    void add(Time T1)
    {
        Hours += T1.Hours;
        Minutes += T1.Minutes;
        Seconds += T1.Seconds;
    }
};

int main()
{
    cout << endl;
    
    Time t1(4, 33, 49);
    //Time t2(2, 30, 76);
    Time t3(2, 27, 11);
    t3.displaydata();
    t3.add(t1);

    t1.displaydata();
    t3.displaydata();

    cout << endl;

    return 0;
}

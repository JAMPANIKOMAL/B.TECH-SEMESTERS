#include <iostream>
using namespace std;

class Time
{
    private:
	int Hours;
	int Minutes;
	int Seconds;
	
    public:
	Time() 
	{
	    cout << "Enter Hours: ";
	    cin >> Hours;
	    cout << "Enter Minutes: ";
	    cin >> Minutes;
	    cout << "Enter Seconds: ";
	    cin >> Seconds;
	    
	    displaydata();
	}

	void displaydata()
	{
	    cout << endl << "Hours: " << Hours << endl;
	    cout << "Minutes: " << Minutes << endl;
	    cout << "Seconds: " << Seconds << endl;
	}
};

int main()
{
    cout << endl;
    
    Time t1;
    
    cout << endl;

    return 0;
}

//Type Conversion

#include <iostream>
using namespace std;

class Minutes
{
    private:
	int Minutes1;
	
    public:
	Minutes() {}

        Minutes(int m)
	{
	    Minutes1 = m;
	}

	int getminutes()
	{
	    return Minutes1;
	}
};


class Time
{
    private:
	int Hours;
	
    public:
	Time() {}

        Time(int h)
	{
	    Hours = h;
	}

	void displaydata()
	{
	    cout << "Hours: " << Hours << endl;
	}

	void operator = (Minutes M); //FORWARD DECLARATION
};

void Time :: operator = (Minutes M)
{
    Hours = M.getminutes();
}

int main()
{
    Time t1(2);
    Minutes M1(30);
    t1 = M1;
    t1.displaydata();


    return 0;
}

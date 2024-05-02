//TEST MARKS CLASS

#include <iostream>
using namespace std;

class Test
{
    private:
	string subject_1;
	int marks_1;
	string subject_2;
	int marks_2;
    
    public:
	void setdata()
	{
	    subject_1 = "Maths";
	    marks_1 = 93;
	    subject_2 = "Physics";	;
	    marks_2 = 89;
	}

	float grade();
};

float Test :: grade()
{
    return (marks_1 + marks_2)/20;
}

int main()
{
    Test t1;
    t1.setdata();
    cout << "Grade: " << (float)t1.grade() << endl;

    return 0;
} 
//Create a class student that stores roll_no, name. Create a class test that stores marks obtained in five subjects. Class result derived from student and test contains the total marks and percentage obtained in test. Input and display information of a student.

//Complete This.

#include <iostream>
using namespace std;

class student
{
    protected:
        int roll_no;
        string name;
    
    public:
        student()
        {
            cout << "Enter Your Name: ";
            cin >> name;

            cout << "Enter Your Rollno: ";
            cin >> roll_no;
        }
};

class test
{
    protected:
        int marks[5];
    
    public:
        test()
        {
            cout << "Enter Your 5 Subjetcs Marks: ";

        }
};

class result : public student, public test
{
    protected:
        int total_marks;
        float percentage;
};

int main()
{


    return 0;
}
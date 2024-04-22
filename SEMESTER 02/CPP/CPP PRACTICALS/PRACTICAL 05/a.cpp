//Write a Program to illustrate the use of pointers to objects which are related by inheritance.

#include <iostream>
using namespace std;

class person
{
    private:
        string name;
        long long mobile_number;

    public:
        void scanpersondetails()
        {
            cout << "Enter Your Name: ";
            getline(cin, name);
            cout << "Enter Your Mobile Number: ";
            cin >> mobile_number;
        }

        void printpersondetails()
        {
            cout << "Name: " << name << endl;
            cout << "Mobile Number: " << mobile_number << endl;
        }
};

class student : public person
{
    private:
        string course;
        long fees;

    public:
        void scanstudentdetails()
        {
            cout << "Enter Your Course Name: ";
            getline(cin >> ws, course);
            cout << "Enter Your fees: ";
            cin >> fees;
        }

        void printstudentdetails()
        {
            cout << "Course: " << course << endl;
            cout << "Fees: " << fees << endl;
        }
};

int main()
{
    cout << endl;

    student *student1;
    student student2;

    student1 = &student2;
    
    student1 -> scanpersondetails();
    student1 -> scanstudentdetails();
    cout << endl;

    student1 -> printpersondetails();
    student1 -> printstudentdetails();

    cout << endl;
    
    return 0;
}
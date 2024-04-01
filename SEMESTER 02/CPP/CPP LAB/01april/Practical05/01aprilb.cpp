//Write a Program to illustrate the use of pointers to objects which are related by inheritance.

#include <iostream>
using namespace std;

class person
{
    private:
        string name;
        long long mobile_number;
    public:
        void scandetailsb()
        {
            cout << "Enter Your Name: ";
            getline(cin, name);
            cout << "Enter Your Mobile Number: ";
            cin >> mobile_number;
        }
        void printdetailsb()
        {
            cout << "Name: " << name << endl;
            cout << "Mobile Number: " << mobile_number << endl;
        }
};

class student : public person
{
    private:
        string course;
        int fees;
    public:
        void scandetailsd1()
        {
            cout << "Enter Your Course Name: ";
            cin >> course;
            cout << "Enter Your fees: ";
            cin >> fees;
        }
        void printdetailsd1()
        {
            cout << "Course: " << course << endl;
            cout << "Fees: " << fees << endl;
        }
};

int main()
{
    student *student1;
    student student2;
    student1 = &student2;
    cout << endl;
    
    student1 -> scandetailsb();
    student1 -> scandetailsd1();
    cout << endl;
    student1 -> printdetailsb();
    student1 -> printdetailsd1();
    cout << endl;
    
    return 0;
}
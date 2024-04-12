//Create a C++ class called Student with private data members name, rollNumber, and grade. Implement public member functions setData() to set the data members, displayData() to display the data members.

#include<iostream>
using namespace std;

class Student 
{
    private: 
        string name;
        int rollnumber;
        float grade;

    public:
        void setData()
        {
            name = "JKC";
            rollnumber = 54;
            grade = 7.73;
        }
        void displayData()
        {
            cout << "Name :" << name << endl;
            cout << "Roll Number: " << rollnumber << endl;
            cout << "Grade: " << grade << endl;
        }
};

int main()
{
    cout << endl;
    Student s1;
    s1.setData();
    s1.displayData();
    
    cout << endl;

    return 0;
}
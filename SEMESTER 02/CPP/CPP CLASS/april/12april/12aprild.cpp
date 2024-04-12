//Create a C++ class called Student with private data members name, rollNumber, and grade. Implement public member functions setData() to set the data members, displayData() to display the data members, and calculateGrade() to calculate the grade based on marks obtained. Ensure that name and rollNumber are private while grade is public.

#include<iostream>
using namespace std;

class Student 
{
    private: 
        string name;
        int rollnumber;

    public:
        char grade;
        void setData()
        {
            name = "JKC";
            rollnumber = 54;
            //grade = 'A';
        }
        void displayData()
        {
            cout << "Name :" << name << endl;
            cout << "Roll Number: " << rollnumber << endl;
            cout << "Grade: " << grade << endl;
        }
        void calculateGrade(int marks)
        {
            if(100 >= marks && marks >= 91)
            {
                grade = 'O';
            }
            else if(90 >= marks && marks >= 81)
            {
                grade = 'A';
            }
            else if(80 >= marks && marks >= 71)
            {
                grade = 'B';
            }
            else if(70 >= marks && marks >= 61)
            {
                grade = 'C';
            }
            else if(60 >= marks && marks >= 51)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }
        }
};

int main()
{
    cout << endl;
    Student s1;
    s1.setData();
    s1.calculateGrade(91);
    s1.displayData();
    
    cout << endl;

    return 0;
}
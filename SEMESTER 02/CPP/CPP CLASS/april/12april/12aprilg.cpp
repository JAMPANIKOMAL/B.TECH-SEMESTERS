/*You are tasked with developing a student management system for a school.
The system should allow users to perform various operations such as adding new students, updating student information, deleting student records, and displaying student details.
Each student record should contain the student's name, roll number, and marks obtained in different subjects. The system should also calculate the percentage of each student based on their marks.
Additionally, the system should keep track of the total number of student records stored in the system. Implement the system using object-oriented programming concepts in C++.*/

//Didn't use sir's method. Refer sir's method also(code with aashutosh).

#include<iostream>
#include<vector>
using namespace std;

class Student
{
    private:
        string name;
        int rollnumber;
        int marks[3];
    public:
        void setData()
        {
            cout << "Enter your Name: ";
            cin >> name;
            cout << "Enter your Roll Number: ";
            cin >> rollnumber;
            cout << "Enter your 3 Marks: " << endl;
            cin >> marks[0] >> marks[1] >> marks[2];
        }
        void displayData()
        {
            cout << "Name: " << name << endl;
            cout << "Roll Number: "  << rollnumber << endl;
            cout << "3 Marks: " <<  marks[0] << " " << marks[1] << " " << marks[2] << endl;
            cout << "Percentage: " << ((marks[0] + marks[1] + marks[2])/3) << " %" << endl;
        }
};

void addstudent();
void displaystudents();
vector <Student> students;

int main()
{
    cout << endl;
    
    int choice;

    while(true)
    {
        cout << "Select a choice from the following: " << endl;
        cout << "1. Add Student." << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                addstudent();
                break;
            }
            case 2:
            {
                displaystudents();
                break;
            }
            case 3:
            {
                exit(1);
                break;
            }
        }
    }
    cout << endl << endl;

    return 0;
}

void addstudent()
{
    Student S;
    S.setData();
    students.push_back(S);
    cout << endl;
}

void displaystudents()
{
    for(int i = 0; i < students.size(); i++)
    {
        cout << endl;
        students[i].displayData();
        cout << endl;
    }
}


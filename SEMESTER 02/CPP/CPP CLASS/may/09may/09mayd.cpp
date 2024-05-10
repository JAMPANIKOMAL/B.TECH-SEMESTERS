//2. MULTILEVEL INHERITANCE
//HAS A PROBLEM

#include <iostream>
using namespace std;

class Person
{
    public:
        void display_Person()
        {
            cout << "Person Class" << endl;
        }
};

class Student : public Person
{
    public:
        void display_Student()
        {
            cout << "Student Class" << endl;
        }
};

class ITStudent : public Student
{
    public:
        void display_ITStudent()
        {
            display_Person();
            display_Student();
            cout << "ITStudent Class" << endl;
        }
};

int main()
{
    cout << endl;

    ITStudent i;

    i.display_ITStudent();

    cout << endl;

    return 0;
}
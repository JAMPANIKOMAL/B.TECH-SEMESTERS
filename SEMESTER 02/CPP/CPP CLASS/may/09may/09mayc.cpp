//2. MULTILEVEL INHERITANCE

#include <iostream>
using namespace std;

class Person
{
    public:
        void display1()
        {
            cout << "Person Class" << endl;
        }
};

class Student : public Person
{
    public:
        void display2()
        {
            cout << "Student Class" << endl;
        }
};

class ITStudent : public Student
{
    public:
        void display3()
        {
            cout << "ITStudent Class" << endl;
        }
};

int main()
{
    cout << endl;

    Person p;
    Student s;
    ITStudent i;

    p.display1();
    cout << endl;

    s.display2();
    s.display1();
    cout << endl;

    i.display3();
    i.display2();
    i.display1();

    cout << endl;

    return 0;
}
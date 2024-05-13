//SINGLE INHERITANCE

#include <iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;

    public:
        void set_person_data()
        {
            cout << "Enter your Name: ";
            getline(cin, name);
            cout << "Enter your Age: ";
            cin >> age;
        }

        void display_person_data()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

class Teacher : public Person
{
    private:
        string subject;
        long salary;

    public:
        void set_teacher_data()
        {
            set_person_data();
            cout << "Enter the subject you teach: ";
            cin >> subject;
            cout << "Enter your Salary: ";
            cin >> salary;
        }

        void display_teacher_data()
        {
            display_person_data();
            cout << "Proffesion: " << subject << " Teacher" << endl;
            cout << "Salary: " << salary << endl;
        }
};

int main()
{
    cout << endl;

    Teacher T1;

    T1.set_teacher_data();
    cout << endl;
    
    T1.display_teacher_data();

    cout << endl;

    return 0;
}
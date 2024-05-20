//Write a C++ program to display employee information using multiple inheritance.

#include <iostream>
using namespace std;

class employee
{
    private:
        string name;
        long long mobileno;
        long emplyeeid;
        long salary;

    public:
        void get_employee_data(string n, long long m, long e, long s)
        {
            name = n;
            mobileno = m;
            emplyeeid = e;
            salary = s;
        }

        void print_employee_data()
        {
            cout << "Name: " << name << endl;
            cout << "Mobile Number: " << mobileno << endl;
            cout << "Employee ID: " << emplyeeid << endl;
            cout << "Salary: " << salary << endl;
        }
};

class teacher : public employee
{
    private:
        string profession = "Teacher";
        string subject;

    public:
        void get_teacher_data(string s)
        {
            subject = s;
        }

        void print_teacher_data()
        {
            cout << "Profession: " << profession << endl;
            cout << "Subject: " << subject << endl;
        }
};

class engineer : public employee
{
    private:
        string profession = "Engineer";
        string domain;

    public:
        void get_engineer_data(string s)
        {
            domain = s;
        }

        void print_engineer_data()
        {
            cout << "Profession: " << profession << endl;
            cout << "Domain: " << domain << endl;
        }
};

int main()
{
    //cout << endl;
    teacher t1;
    t1.get_employee_data("Ram", 9123434323, 01, 16000);
    t1.get_teacher_data("History");
    cout << endl;
    t1.print_employee_data();
    t1.print_teacher_data();
    //cout << endl;

    engineer e1;
    e1.get_employee_data("Laxman", 9878653910, 02, 32000);
    e1.get_engineer_data("Cybersecurity");
    cout << endl;
    e1.print_employee_data();
    e1.print_engineer_data();
    cout << endl;

    return 0;
}
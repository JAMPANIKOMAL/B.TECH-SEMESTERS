//Write a C++ program to Store and Display Employee Information.

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
        void getdata(string n, long long m, long e, long s)
        {
            name = n;
            mobileno = m;
            emplyeeid = e;
            salary = s;
        }

        void printdata()
        {
            cout << "Name: " << name << endl;
            cout << "Mobile Number: " << mobileno << endl;
            cout << "Employee ID: " << emplyeeid << endl;
            cout << "Salary: " << salary << endl;
        }
};

int main()
{
    cout << endl;
    employee e1;
    e1.getdata("Ram", 912348765, 01, 16000);
    e1.printdata();

    cout << endl;

    return 0;
}
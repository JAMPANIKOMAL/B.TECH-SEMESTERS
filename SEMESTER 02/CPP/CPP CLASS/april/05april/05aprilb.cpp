//Constructor
//Complete this.

#include<iostream>
using namespace std;

class student
{
    private:
        double rollno;
        string name;
        double fees;
    public:
        student()
        {
            cout << "Enter Your Roll Number: ";
            cin >> rollno;
            cout << "Enter Your Name: ";
            cin >> name;
            cout << "Enter Your Fees: ";
            cin >> fees;
        }
        void display()
        {
            cout << endl << "Roll Number: " << rollno;
            cout << endl << "Name: " << name;
            cout << endl << "Fees: " << fees;
        }
};

int main()
{
    cout << endl;
    student s1;
    s1.display();
    cout << endl << endl;

    return 0;
}
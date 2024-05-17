//Create a class student having private members marks, name and public members rollno, getdata(), printdata(),. Demonstrate concept of pointer to class members for array of 3 objects.

#include <iostream>
#include <string>
using namespace std;

class student
{
    private:
        int marks;
        string name;
    
    public:
        long rollno;

        void getdata()
        {
            cout << "Enter your Name: ";
            getline(cin, name); 
            cout << "Enter your Marks: ";
            cin >> marks;
            cout << "Enter your Rollno: ";
            cin >> rollno;
        }

        void printdata()
        {
            cout << "Name: " << name << endl;
            cout << "Marks: " << name << endl;
            cout << "Rollno: " << rollno << endl;
        }
};

int main()
{
    cout << endl;

    student s[3];
    student * sptr = s;

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter Student " << i + 1 << " details: " << endl;
        (sptr + i) -> getdata();
        cout << endl;
        (sptr + i) -> printdata();
        cout << endl;
    }

    cout << endl;

    return 0;
}
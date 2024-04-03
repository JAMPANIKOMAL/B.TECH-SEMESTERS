// PROGRAM TO ILLUSTRATE FUNCTION OVERLOADING.
#include <iostream>
using namespace std;

void student_name(string sn);
void enrollment_number(long long en);

int main()
{
    string sn;
    long long en;
    cout << endl << "Enter the Name of the student: ";
    // cin >> sn;
    getline(cin, sn); // getline is used to overcome limitation of cin if space is used.
    cout << "Enter the Enrollment Number of the student: ";
    cin >> en;
    cout << endl;
    student_name(sn);
    enrollment_number(en);
    cout << endl << "Length of the name of the student: " << sn.length();
    int loen = 0;
    //int i = 0;
    while (en > 0)
    {
        en = en / 10;
        loen = loen + 1;
    }
    cout << endl << "Length of the Enrollment Number: " << loen << endl << endl;

    return 0;
}

void student_name(string sn)
{
    cout << "Student Name: " << sn << endl;
}

void enrollment_number(long long en)
{
    cout << "Enrollment Number: " << en << endl;
}

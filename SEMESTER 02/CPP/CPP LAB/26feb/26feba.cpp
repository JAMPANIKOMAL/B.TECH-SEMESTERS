//PROGRAM TO ILLUSTRATE FUNCTION OVERLOADING.
#include <iostream>
using namespace std;

void school (string s);
void branch (string b);
void number_of_students(int nos);

int main()
{
    string s, b;
    int nos;
    cout << endl << "Enter School name: ";
    cin >> s;
    cout << "Enter Branch name: ";
    cin >> b;
    cout << "Enter the Number of the Students in that branch: ";
    cin >> nos;
    cout << endl;
    school(s);
    branch(b);
    number_of_students(nos);
    cout << endl;

    return 0;
}

void school (string s)
{
    cout << "School: " << s << endl;
}

void branch (string b)
{
    cout << "Branch: " << b << endl;
}

void number_of_students(int nos)
{
    cout << "Number of the Students in that branch: "  << nos << endl;
}

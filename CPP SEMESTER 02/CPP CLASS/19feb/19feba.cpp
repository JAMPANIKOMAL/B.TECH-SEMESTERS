#include <iostream>
using namespace std;

enum Gender 
{
    Male,
    Female
};

int main ()
{
    Gender gender = Male; //gender is a variable and male which is 0 is assigned to it.
    switch (gender)
    {
        case Male:
        {
            cout << "Gender is Male.";
            break;
        }
        case Female:
        {
            cout << "Gender is Female.";
            break;
        }
        default:
        {
            cout << "Value can be Male or Female.";
        }
    }

    return 0;
}
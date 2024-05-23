//Design a control structure that takes a user’s age and outputs whether they are a minor, an adult, or a senior citizen.

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    
    if(age < 18)
    {
        cout << "Minor" << endl;
    }
    else if(18 <= age < 60)
    {
        cout << "Adult" << endl;
    }
    else
    {
        cout << "Senior Citizen." << endl;
    }

    return 0;
}
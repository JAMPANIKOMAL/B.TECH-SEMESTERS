#include <iostream>
using namespace std;

enum class DayOfWeek 
{
    SUNDAY = 0,
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
};

void printDay(int dayNumber) 
{
    if (dayNumber < 0 || dayNumber > 6) 
    {
        cout << "Invalid input. Please enter a number between 0 and 6." << endl;
        return;
    }

    switch (dayNumber) 
    {
        case 0:
        {
            cout << "Sunday" << endl;
            break;
        }
        case 1:
        {
            cout << "Monday" <<     endl;
            break;
        }
        case 2:
        {
            cout << "Tuesday" <<     endl;
            break;
        }
        case 3:
        {
            cout << "Wednesday" <<     endl;
            break;
        }
        case 4:
        {
            cout << "Thursday" <<     endl;
            break;
        } 
        case 5:
        {
            cout << "Friday" <<     endl;
            break;
        }
        case 6:
        {
            cout << "Saturday" <<     endl;
            break;
        } 
    }
}

int main() 
{
    cout << endl;
    
    int dayInput;
    cout << "Enter a number between 0 and 6 to represent a day of the week (0: Sunday, 6: Saturday): ";
    cin >> dayInput;
    printDay(dayInput);
    
    cout << endl;
    return 0;
}

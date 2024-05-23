//Create an enum type for days of the week and write a function to print out the day based on an integer input. C++

#include <iostream>
#include <string>
using namespace std;

enum class DayOfWeek { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

void printDay(int dayNumber) 
{
    switch (dayNumber) 
    {
        case static_cast <int> (DayOfWeek :: sunday):
        {
            cout << "Sunday" << endl;
            break;
        }
        case static_cast <int> (DayOfWeek :: monday):
        {
            cout << "Monday" <<     endl;
            break;
        }
        case static_cast <int> (DayOfWeek :: tuesday):
        {
            cout << "Tuesday" <<     endl;
            break;
        }
        case static_cast <int> (DayOfWeek :: wednesday):
        {
            cout << "Wednesday" <<     endl;
            break;
        }
        case static_cast <int> (DayOfWeek :: thursday):
        {
            cout << "Thursday" <<     endl;
            break;
        } 
        case static_cast <int> (DayOfWeek :: friday):
        {
            cout << "Friday" <<     endl;
            break;
        }
        case static_cast <int> (DayOfWeek :: saturday):
        {
            cout << "Saturday" <<     endl;
            break;
        } 
        default:
        {
            cout << "Invalid Choice!";
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

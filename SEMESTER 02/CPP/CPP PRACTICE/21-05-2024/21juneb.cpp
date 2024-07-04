#include <iostream>
#include <string>
using namespace std;

enum day { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

string printDay(day d) 
{
    switch (d) 
    {
        case sunday: 
        {
            return "Sunday";
        }
        case monday: 
        {
            return "Monday";
        }
        case tuesday: 
        {
            return "Tueday";
        }
        case wednesday: 
        {
            return "Wednesday";
        }
        case thursday: 
        {
            return "Thursday";
        }
        case friday: 
        {
            return "Friday";
        }
        case saturday: 
        {
             return "Saturday";
        }
        default: 
        {
            return "Invalid Choice!";
        }
    }
}

int main() 
{
    int a;
    cin >> a;
    day d = day (a);
    cout << printDay(d);
    return 0;
}

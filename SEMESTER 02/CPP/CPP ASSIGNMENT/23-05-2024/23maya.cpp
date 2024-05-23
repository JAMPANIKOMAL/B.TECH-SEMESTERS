//Create an enum type for days of the week and write a function to print out the day based on an integer input. C++

#include <iostream>
#include <string>
using namespace std;

enum day { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

string printDay(enum day d) 
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
    enum day d = static_cast <day> (a);
    cout << printDay(d);
    return 0;
}

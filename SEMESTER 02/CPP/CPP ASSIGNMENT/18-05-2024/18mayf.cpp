#include <iostream>
using namespace std;

enum DayOfWeek 
{
    SUNDAY = 0,
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
};

void printday();

int main() 
{
    cout << endl;

    printday();
    
    cout << endl;
    return 0;
}

void printday()
{
    enum DayOfWeek d1;
    int dayInput;
    cout << "Enter a number between 0 and 6 to represent a day of the week (0: Sunday, 6: Saturday): ";
    cin >> dayInput;
    cout << dayInput;

}

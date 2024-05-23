//Define two base classes Motor and Vehicle. Create a derived class ElectricCar that inherits from both Motor and Vehicle. Include unique attributes and functions for each class and demonstrate how ElectricCar can utilize the properties and methods from both base classes.

#include <iostream>
using namespace std;

class Motor
{
    public:
        void startmotor()
        {
            cout << "Starting Motor!" << endl;
        }
};

class Vehicle
{
    public:
        void modeoftransport()
        {
            cout << "Road!" << endl;
        }

};

class ElectricCar : public Motor, public Vehicle
{
    public:
        void range()
        {
            cout << "Range = 300 km" << endl;;
        }
};

int main()
{
    ElectricCar E1;

    E1.modeoftransport();
    E1.range();
    E1.startmotor();

    return 0;
}
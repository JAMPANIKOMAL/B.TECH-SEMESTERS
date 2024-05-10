//5. Hybrid Inheritance

#include <iostream>
using namespace std;

class Car
{
    public:
        void display1()
        {
            cout << "Car Class" << endl;
        }
};

class FuelCar : public Car
{
    public:
        void display2()
        {
            cout << "FuelCar Class" << endl;
        }
};

class ElectricCar : public Car
{
    public:
        void display3()
        {
            cout << "ElectricCar Class" << endl;
        }
};

class HybridCar : public FuelCar, public ElectricCar
{
    public:
        void display4()
        {
            cout << "HybridCar Class" << endl;
        }
};

int main()
{
    cout << endl;

    Car c;
    FuelCar f;
    ElectricCar e;
    HybridCar h;

    c.display1();
    cout << endl;

    f.display2();
    f.display1();
    cout << endl;

    e.display3();
    e.display1();
    cout << endl;

    h.display4();
    h.display3();
    h.display2();
    cout << endl;

    return 0;
}


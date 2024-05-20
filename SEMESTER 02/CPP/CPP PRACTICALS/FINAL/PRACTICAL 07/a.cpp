//Write a C++ program to demonstrate simple inheritance.

#include <iostream>
using namespace std;

class vehicle
{
    private:
        string brand;
        string model;
        long price;
    
    public:
        vehicle()
        {
            cout << "Enter Brand name: ";
            cin >> brand;
            cout << "Enter Model name: ";
            cin >> model;
            cout << "Enter Price: ";
            cin >> price;
        }

        void display_vehicle()
        {
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
        }
};

class car : public vehicle
{
    private:
        string type = "Car";
    
    public:
        void display_car()
        {
            cout << "Type: " << type << endl;;
            display_vehicle();
        }
};

int main()
{
    cout << endl;
    car c1;
    cout << endl;
    c1.display_car();
    cout << endl;
    return 0;
}
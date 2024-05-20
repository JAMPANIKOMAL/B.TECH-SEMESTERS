//Create an Abstract class vehicle having average as data and pure virtual function getdata () and putdata (). Derive class car and truck from class vehicle having data members: fuel type (petrol, diesel, CNG) and no of wheels respectively. Write a main () that enters the data of two cars and a truck and display the details of them.

#include <iostream>
using namespace std;

class vehicle
{
    protected:
        float average;

    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class car : public vehicle
{
    private:
        string name;
        string fuel_type;
        int noofwheels;

    public:
        void getdata()
        {
            cout << "Enter name of car: ";
            cin >> name;
            cout << "Enter Fuel Type:";
            cin >> fuel_type;
            cout << "Enter number of wheels: ";
            cin >> noofwheels;
            cout << "Enter Average: ";
            cin >> average;
        }

        void putdata()
        {
            cout << "Name: " << name << endl;
            cout << "Fuel Type: " << fuel_type << endl;
            cout << "Number of Wheels: " << noofwheels << endl;
            cout << "Average: " << average << endl;
        }
};

class truck : public vehicle
{
    private:
        string name;
        string fuel_type;
        int noofwheels;

    public:
        void getdata()
        {
            cout << "Enter name of truck: ";
            cin >> name;
            cout << "Enter Fuel Type:";
            cin >> fuel_type;
            cout << "Enter number of wheels: ";
            cin >> noofwheels;
            cout << "Enter Average: ";
            cin >> average;
        }

        void putdata()
        {
            cout << "Name: " << name << endl;
            cout << "Fuel Type: " << fuel_type << endl;
            cout << "Number of Wheels: " << noofwheels << endl;
            cout << "Average: " << average << endl;
        }
};

int main()
{
    cout << endl;

    vehicle * v1;
    car c1;
    truck t1;

    v1 = &c1;
    v1 -> getdata();
    cout << endl;
    v1 -> putdata();
    cout << endl;

    v1 = &t1;
    v1 -> getdata();
    cout << endl;
    v1 -> putdata();
    cout << endl;

    cout << endl;

    return 0;
}
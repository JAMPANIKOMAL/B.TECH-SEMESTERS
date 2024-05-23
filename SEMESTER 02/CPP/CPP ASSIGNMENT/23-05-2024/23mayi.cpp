//Define a base class Employee with a virtual function calculatePay(). Derive two classes from Employee: HourlyEmployee and SalariedEmployee. Override the calculatePay() function in both derived classes to calculate the pay based on hourly wages and salary, respectively. Create an array of Employee pointers and demonstrate polymorphic behavior by calling calculatePay() on each element.

#include <iostream>
using namespace std;

class Employee
{
    public:
        virtual void calculatePay()
        {
            cout << "Base Pay: " << 15000 << endl;
        }
};

class HourlyEmployee : public Employee
{
    private:
        int hours = 300;
        int payperhour = 100;
    
    public:
        void calculatePay()
        {
            cout << "Pay: " << hours * payperhour << endl;
        }
};

class SalariedEmployee : public Employee
{
    private:
        int salary = 25000;
    
    public:
        void calculatePay()
        {
            cout << "Pay: " << salary << endl;
        }
};

int main()
{
    Employee * E[3];
    Employee E1;
    HourlyEmployee H1;
    SalariedEmployee S1;

    E[0] = &E1;
    E[1] = &H1;
    E[2] = &S1;

    E[0]-> calculatePay();
    E[1] -> calculatePay();
    E[2] -> calculatePay();

    return 0;
}
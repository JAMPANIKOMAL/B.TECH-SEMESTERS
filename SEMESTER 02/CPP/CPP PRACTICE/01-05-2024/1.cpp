//CAR CLASS

#include <iostream>
using namespace std;

class Car
{
    private:
	string model;
	long price;
	long milage;
    public:
	void setdata()
	{
	    model = "Tata Nano";
	    price = 149000;
	    milage = 0;
	}
	
	void displaydata()
	{
	    cout << "Model: " << model << endl;
	    cout << "Price: " << price << endl;
	    cout << "Milage: " << milage << endl;    
	}
};

int main()
{
    Car c1;
    c1.setdata();
    c1.displaydata();

    return 0;
}
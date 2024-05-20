class Car 
{
    private:
        string brand;
        int year;

    public:
        Car(string brand, int year) : brand(brand), year(year) {}

        string getBrand()
        {
            return brand;
        }

    void accelerate() 
    {
       cout << "Car is accelerating!" << endl;
    }
};

class Shape 
{
    public:
        virtual double getArea();  
};

class Circle : public Shape 
{
    private:
        double radius;
        
    public:
    Circle(double radius) : radius(radius) {}

    double getArea()
    {
        return Math.PI * radius * radius;
    } 
};

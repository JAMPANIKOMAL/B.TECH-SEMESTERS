//Define an abstract class Drawable with a pure virtual function draw(). Derive two classes from Drawable: Line and Circle. Implement the draw() function in both derived classes to display information about the shapes being drawn. Create a vector of Drawable pointers and demonstrate polymorphism by iterating through the vector and calling draw() on each element.

#include <iostream>
#include <vector>
using namespace std;

class Drawable
{
    public:
        virtual void draw() = 0;
};

class Line : public Drawable
{
    public:
        void draw()
        {
            cout << "Drawing Line!" << endl;
        }
};

class Circle : public Drawable
{
    public:
        void draw()
        {
            cout << "Drawing Circle!" << endl;
        }
};

int main()
{
    vector <Drawable *> D;

    Line L1;
    Circle C1;

    D.push_back(&L1);
    D.push_back(&C1);

    D[0] -> draw();
    D[1] -> draw();


    return 0;
}
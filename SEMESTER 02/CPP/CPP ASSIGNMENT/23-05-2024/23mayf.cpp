/*Define a class Book with private members title, author, and price.
Include the following:
- A default constructor that initializes the members with default values.
- A parameterized constructor that initializes the members with given values.
- A destructor that prints a message when an object is destroyed.
- Member functions to set and get the values of the private members.
Demonstrate the creation and destruction of Book objects.*/

#include <iostream>
using namespace std;

class Book
{
    private:
        string title;
        string author;
        int price;

    public:
        Book(){title = "A Tale of a Son"; author = "J.K Chowdary"; price = 116;}
        Book(string t, string a, int p) {title = p; author = a; price = p;}
        ~Book(){cout << "Object Destroyed!";}
        void set()
        {
            cin >> title >> author >> price;
        }
        void get()
        {
            cout << title << author << price;
        }
};

int main()
{
    Book b1;
    Book b2("R.R Martin", "A song of ice and fire", 3000);
    Book b3;
    b3.set();
    b3.get();
}
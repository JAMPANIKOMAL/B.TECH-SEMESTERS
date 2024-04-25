/*Program: Stock Management System

You are tasked with developing a stock management system to efficiently handle two types of stocks: stock1 and stock2. Each stock type has its own set of attributes and functionalities.

1.stock1 Class: This represents a type of stock characterized by a unique code, the quantity of items in stock, and the price per item. Implement the following functionalities:
    •Constructor to initialize the stock with given values.
    •Method to display the details of the stock (disp()).
    •Accessor methods to retrieve the code, item quantity, and price.
    •Implicit conversion operator to calculate the total value of the stock.

2.stock2 Class: This represents another type of stock identified by a code and its total value. Implement the following functionalities:
    •Constructors to initialize the stock with default values, given values, and by corwerting a stock1
    object.
    •Method to display the details of the stock (disp()).

3. Main Functionality: Your program should allow users to:
    •Create instances of stock1 and stock2.
    •Display the details of each stock.
    •Calculate and display the total value of stock1.
    •Convert a stock1 object to a stock2 object and display its details.*/

//Not Completed.

#include <iostream>
using namespace std;

class stock
{
    public:
        class stock1
        {
            private:
                string item_code;
                int price;
                int itmesno;
        
            public:
                stock1(string a, int b, int c)
                {
                    item_code = a;
                    itmesno = b;
                    price = c;
                }

                void displaydata()
                {
                    cout << "Item Code: " << item_code << endl;
                    cout << "Item Price: " << price << endl;
                    cout << "Total number of items: " << itmesno << endl;
                }
        };

        class stock2
        {
            public:

        };
    
};

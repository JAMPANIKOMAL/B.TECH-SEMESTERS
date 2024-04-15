//Write an oop program to demonstrate e-kart where user can insert the item and its price. display the total price and display insert and delete price and item.

//For multiple users.

#include <iostream>
#include <vector>
using namespace std;

class Cart
{
    private:
        string username;
        string userid;    
    public:
        void setCartdata()
        {
            cout << "Enter User Name: ";
            cin >> username;
            cout << "Enter User Id: ";
            cin >> userid;
        }

        class item
        {
            private:
                
            public:
                string itemname;
                long int price;
                void setitemdata()
                {
                    cout << "Enter Item Name: ";
                    cin >> itemname;
                    cout << "Enter the price of the item: ";
                    cin >> price;
                }
        };

        vector <Cart :: item> ci;

        void additem()
        {
            cout << endl;
            item i1;
            i1.setitemdata();
            ci.push_back(i1);
        }

        void deleteitem()
        {
            int i;
            cout << endl << "Enter the item number to be deleted: ";
            cin >> i;
            i--;
            ci.erase(ci.begin() + i);
        }

        void dispalyitem(item i)
        {
            cout << "Item Name: " << i.itemname << endl;
            cout << "Price: " << i.price << endl;
        }

        void dispalyitems()
        {
            cout << endl;
            for(int i = 0; i < ci.size(); i++)
            {
                cout << "Item Number: " << i+1 << endl;
                dispalyitem(ci[i]);
                cout << endl;
            }
        }

        void dispalytotalprice()
        {
            int totalprice = 0;
            cout << endl;
            for(int i = 0; i < ci.size(); i++)
            {
                totalprice += ci[i].price;
            }
            cout << "Total Price: " << totalprice << endl; 
        }
};

int main()
{
    cout << endl;
    Cart U1;
    U1.setCartdata();

    int choice;

    while(true)
    {
        cout << endl;
        cout << "Select a choice from the following: " << endl;
        cout << "1. Add an Item." << endl;
        cout << "2. Delete an Item" << endl;
        cout << "3. Display Items" << endl;
        cout << "4. Display Total Price" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                U1.additem();
                break;
            }
            case 2:
            {
                U1.deleteitem();
                break;
            }
            case 3:
            {
                U1.dispalyitems();
                break;
            }
            case 4:
            {
                U1.dispalytotalprice();
                break;
            }
            case 5:
            {
                exit(1);
                break;
            }
        }
    }
    cout << endl << endl;

    return 0;
}
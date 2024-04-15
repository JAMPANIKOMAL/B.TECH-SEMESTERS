//Write an oop program to demonstrate e-kart where user can insert the item and its price. display the total price and display insert and delete price and item.

//Assuming only one user.

#include <iostream>
#include <vector>
using namespace std;

class Cart
{
    private:
        int userid;
        string username;
    public:
        Cart()
        {
            username = "User 01";
            userid = 01;
        }

        class item
        {
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

                void dispalyitemdata()
                {
                    cout << "Item Name: " << itemname << endl;
                    cout << "Price: " << price << endl;
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
            if(ci.empty())
            {
                cout << endl << "No items available to delete!" << endl;
            }
            else
            {
                int i;
                cout << endl << "Enter the item number to be deleted: ";
                cin >> i;
                i--;
                if(i <= ci.size())
                {
                    ci.erase(ci.begin() + i);
                    cout << "Item deleted successfully!" << endl;
                }
                else
                {
                    cout << "Invalid Item Number!" << endl;
                }
            }
        }

        void dispalyitems()
        {
            if(ci.empty())
            {
                cout << endl << "No items available!" << endl;
            }
            else
            {
               cout << endl;
                for(int i = 0; i < ci.size(); i++)
                {
                    cout << "Item Number: " << i+1 << endl;
                    ci[i].dispalyitemdata();
                    cout << endl;
                } 
            }
        }

        void dispalytotalprice()
        {
            int totalprice = 0;
            for(int i = 0; i < ci.size(); i++)
            {
                totalprice += ci[i].price;
            }
            cout << endl << "Total Price: " << totalprice << endl; 
        }
};

int main()
{
    cout << endl;
    Cart U1;

    int choice;

    cout << "Hello User!" << endl;

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
                cout << endl;
                exit(1);
                break;
            }
        }
    }
    cout << endl << endl;

    return 0;
}
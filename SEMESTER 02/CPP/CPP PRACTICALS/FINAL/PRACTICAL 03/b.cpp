//Write a C++ program to perform Deposit, Withdraw, Display, Exit operations.

#include<iostream>
using namespace std;

class bankaccount
{
    private:
        string name;
        long long accountno;
        long balance;

    public:
        bankaccount()
        {
            cout << "Enter your Name: ";
            getline(cin, name);
            cout << "Enter your Account Number: ";
            cin >> accountno;
            cout <<"Enter the balance in your Account: ";
            cin >> balance;
        }

        friend void transactions(bankaccount);
};

void transactions(bankaccount b)
{
    int choice;
    while(1)
    {
        cout << endl << "Select an option from the following:";
        cout << endl << "1 --> Deposit";
        cout << endl << "2 --> Withdraw.";
        cout << endl << "3 --> Dispaly.";
        cout << endl << "4 --> To Exit";
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Enter the amount to be deposited: ";
                int tbdeposited;
                cin >> tbdeposited;
                b.balance += tbdeposited;
                break;
            }
            case 2:
            {
                cout << "Enter the amount to withdraw: ";
                int twithdraw;
                cin >> twithdraw;
                if(b.balance >= twithdraw)
                {
                    b.balance -= twithdraw;
                }
                else
                {
                    cout << "Insufficient Balance!" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "Balnce = " << b.balance << endl;
                break;
            }
            case 4:
            {
                printf(" ");
                exit(1);
                break;
            }
            default:
            {
                printf(" Invalid choice.");
                printf(" ");
                break;
            }
        }
    }

}

int main()
{
    cout << endl;

    bankaccount b1;
    transactions(b1);

    cout << endl;
    
    return 0;
}
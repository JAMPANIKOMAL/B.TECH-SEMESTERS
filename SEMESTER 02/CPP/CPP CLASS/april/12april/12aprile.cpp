//Implement a C++ class called BankAccount with private data members balance and accountNumber. Create a friend function named transferFunds outside the class, which takes two BankAccount objects as parameters and transfers a specified amount from one account to another, updating their balances accordingly.

//not working

#include<iostream>
using namespace std;

class BankAccount
{
    private:
        long int balance;
        long int accountNumber;
    public:
        BankAccount(long int b = 0, long int a = 0) : balance(b), accountNumber(a) {}
        void setData(long int b, long int a)
        {
            balance = b;
            accountNumber = a;
        }
        void displayData()
        {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
        friend void tranferfunds(BankAccount B1, BankAccount B2, long int amount);
};

void tranferfunds(BankAccount B1, BankAccount B2, long int amount)
{
    B1.balance = B1.balance - amount;
    B2.balance = B2.balance + amount;
}

int main()
{
    cout << endl;
    BankAccount B1;
    BankAccount B2;
    B1.setData(10000, 1);
    cout << endl;
    B2.setData(20000, 2);

    cout << "Before Transfering Funds: " << endl;
    B1.displayData();
    B2.displayData();
    cout << endl;

    tranferfunds(B1, B2, 10000);

    cout << "After Transfering Funds: " << endl;
    B1.displayData();
    B2.displayData();
    cout << endl << endl;

}
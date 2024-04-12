//Implement a C++ class called BankAccount with private data members balance and accountNumber. Create a friend function named transferFunds outside the class, which takes two BankAccount objects as parameters and transfers a specified amount from one account to another, updating their balances accordingly.

//complete this.

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
        friend void tranferfunds(BankAccount &from, BankAccount &to, long int amount);
};

void tranferfunds(BankAccount &from, BankAccount &to, long int amount)    //Should pass adrress.
{
    if(from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;
    }
    else
    {
        cout << "Insufficient Funds.";
    }
    
}

int main()
{
    cout << endl;
    BankAccount B1(100, 1);
    BankAccount B2(200, 2);

    cout << "Before Transfering Funds: " << endl;
    B1.displayData();
    B2.displayData();
    cout << endl;

    tranferfunds(B1, B2, 101);

    cout << "After Transfering Funds: " << endl;
    B1.displayData();
    B2.displayData();
    cout << endl << endl;

}
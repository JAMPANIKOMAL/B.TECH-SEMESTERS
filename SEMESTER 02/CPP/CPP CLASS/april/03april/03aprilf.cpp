//Using Constructers.

#include<iostream>
using namespace std;

class BankAccount
{
    private:
        static int TotalAccounts;
        int AccountNumber;
        string AccountHolder;
        double Balance;
    public:
        BankAccount(string name, double initialbalance)
        {
            TotalAccounts++;
            AccountNumber = TotalAccounts;
            AccountHolder = name;
            Balance = initialbalance;
        }
        static void dispalyTotalAccounts()
        {
            cout << "Total Accounts Created: " << TotalAccounts << endl;
        }
        void displayAccountDetails()
        {
            cout << "Account Number: " << AccountNumber << endl;
            cout << "Account Holder: " << AccountHolder << endl;
            cout << "Balance: " << Balance << endl;
        }
        void deposit(double amount)
        {
            Balance += amount;
        }
        void withdraw(double amount)
        {
            if(Balance >= amount)
            {
                Balance -= amount;
            }
            else
            {
                cout << "Insufficent Funds!" << endl;
            }
        }
};

int BankAccount :: TotalAccounts = 0;

int main()
{
    cout << endl;
    //Creating two bank accounts.
    BankAccount account1("Ram", 1000.0);
    BankAccount account2("Laxman", 1000.0);

    cout << endl;
    //Dispalying Account Details.
    account1.displayAccountDetails();
    account2.displayAccountDetails();

    cout << endl;
    //Deposit and withdrwal.
    account1.deposit(500.0);
    account2.withdraw(300.0);

    cout << endl;
    //Displaying updated balances.
    account1.displayAccountDetails();
    account2.displayAccountDetails();

    cout << endl;
    //Dispaly total accounts.
    BankAccount :: dispalyTotalAccounts();
    cout << endl;

    return 0;
}
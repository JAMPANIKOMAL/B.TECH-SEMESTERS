#include<iostream>
using namespace std;

string string_copy(string a);
string string_reverse(string a);
bool string_compare(string a, string b);

int main()
{
    string a;

    cout << "\nEnter your first string: ";
    cin >> a;

    while(true)
    {
        cout << "\nSelect your choice: ";
        cout << "\n1. String Copy";
        cout << "\n2. String Reverse";
        cout << "\n3. String Comapre";
        cout << "\n4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                string copy = string_copy(a);
                cout << "Copied string is: ";
                cout << copy << endl;
                break;
            }
            case 2:
            {
                string reversed = string_reverse(a);
                cout << "Reversed string is: ";
                cout << reversed << endl;
                break;
            }
            case 3:
            {
                string b;
                cout << "Enter your second string: ";
                cin >> b;
                bool result = string_compare(a, b);

                if(result == 0)
                {
                    cout << "String not equal << endl";
                }
                else
                {
                    cout << "String equal" << endl;
                }

                break;
            }
            case 4:
            {
                cout << endl;
                exit(0);
                break;
            }
            default:
            {
                cout << "Enter a valid choice! << endl";
                break;
            }
        }
    }
    
    return 0;
}

string string_copy(string a)
{
    return a;
}

string string_reverse(string a)
{
    string b = "";
    for(int i = a.length(); i >= 0; i--)
    {
        b = b + a[i - 1];
    }
    return b;
}

bool string_compare(string a, string b)
{
    for(int i = 0; a[i] != '\0'; i++)
    {
        for(int i = 0; b[i] != '\0'; i++)
        {
            if(a[i] != b[i])
            {
                return 0;
            }
        }
    }
    return 1;
}
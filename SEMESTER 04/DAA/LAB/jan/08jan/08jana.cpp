#include<iostream>
using namespace std;

string string_copy(string a);
string string_reverse(string a);
bool string_compare(string a, string b);

int main()
{
    string a;

    cout << "Enter your first string: ";
    cin >> a;

    cout << "Enter your choice: ";
    cout << "1. String Copy";
    cout << "2. String Reverse";
    cout << "3. String Comapre";
    cout << "3. String Concatnate";
    cout << "5. Exit";

    switch (choice)
    {
        case 1:
        {
            string copy = string_copy(a);
            break;
        }
        case 2:
        {
            string reversed = string_reverse(string a);
            break;
        }
        case 3:
        {
            cout << "Enter your second string: ";
            cin >> b;
            bool result = string_compare(string a, string b);

            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout << "Enter a valid choice!";
            break;
        }
    }

    return 0;
}

string string_copy(string a, string b);
string string_reverse(string a);
string string_compare(string a, string b);
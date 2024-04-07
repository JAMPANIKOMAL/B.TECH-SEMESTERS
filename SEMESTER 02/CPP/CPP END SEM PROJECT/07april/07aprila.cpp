#include<iostream>
using namespace std;

void patientlogin();
void doctorlogin();
void adminlogin();

int main()
{
    cout << "Login Page: ";
    cout << endl << "1. Patient";
    cout << endl << "2. Doctor";
    cout << endl << "3. Admin";
    int loption;
    cin >> loption;
    switch(loption)
    {
        case 1:
        {
           patientlogin(); 
           break;
        }
        case 2:
        {
           doctorlogin(); 
           break;
        }
        case 3:
        {
           adminlogin(); 
           break;
        }
        default:
        {
            cout << "Enter proper input!";
        }
    }

    return 0;
}

void patientlogin()
{
    cout << "Login Page: ";
    cout << endl << "1. Patient";
    cout << endl << "2. Doctor";
    cout << endl << "3. Admin";
    int loption;
    cin >> loption;
    switch(loption)
    {
        case 1:
        {
           patientlogin(); 
           break;
        }
        case 2:
        {
           doctorlogin(); 
           break;
        }
        case 3:
        {
           adminlogin(); 
           break;
        }
        default:
        {
            cout << "Enter proper input!";
        }
    }
}
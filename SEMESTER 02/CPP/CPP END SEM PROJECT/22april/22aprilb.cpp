// C++ program to demonstrate how to read and write arrays to/from files 
#include <fstream> 
#include <iostream> 
#include <vector>

using namespace std; 

int main() 
{ 
	vector <string> usernames;
    ifstream myfile; 
    myfile.open("book1.xlsx");
    string mystring;

    if (myfile.is_open()) 
    {
        myfile >> mystring; 

        while(mystring != "end")
        {
            usernames.push_back(mystring);
            myfile >> mystring;
        }
    }

    for(int i = 0; i < usernames.size(); i++)
    {
        cout << usernames[i];
    }

	return 0; 
}

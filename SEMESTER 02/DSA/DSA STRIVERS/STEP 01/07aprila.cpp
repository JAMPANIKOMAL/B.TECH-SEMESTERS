#include<iostream>
using namespace std;

void dataTypes(string type) 
{
	if(type == "Integer")
	{
		cout << sizeof(int);
		exit;
	}
	else if(type == "Long")
	{
		cout << sizeof(long);
		exit;
	}
	else if(type == "Float")
	{
		cout << sizeof(float);
	}
	else if(type == "Double")
	{
		cout << sizeof(double);
	}
	else if(type == "Character")
	{
		cout << sizeof(char);
	}
	else
	{
		exit;
	}
}


int main()
{
    string type;
    cin >> type;
    dataTypes(type);
}
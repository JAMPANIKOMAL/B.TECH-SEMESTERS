#include<iostream>
using namespace std;

double areaSwitchCase(int ch, vector<double> a) 
{
	int x;
	cin >> x;
	switch(x)
	{
		case 1:
		{
			cin >> ch;
			return (3.14 * ch * ch);
		}
		case 2:
		{
			cin >> a[0] >> a[1];
			double res = a[0] *a[1];
			return (res);
		}
	}
}



int main()
{
    areaSwitchCase(ch, a);
}
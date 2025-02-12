// Practical 05
// Rod cutting problem
// Solving by divide and conquer method

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int max(int a, int b);
int cutrod(vector <int> v, int n);

int main()
{
    vector <int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; 
    
    int n;
    cout << endl << "Enter rod length = ";
    cin >> n;

    int cost = cutrod(prices, n);

    cout << "Maximum price of rod of length " << n << ": " << cost << endl << endl;

    return 0;
}

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int cutrod(vector <int> v, int n) 
{
    if (n == 0) 
    {
        return 0;
    }

    int q = numeric_limits <int> :: min();

    for (int i = 1; i <= n; i++) 
    {
        q = max(q, v[i - 1] + cutrod(v, n - i));
    }

    return q;
}
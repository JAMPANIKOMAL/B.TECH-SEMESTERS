#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n, q;
    cin >> n >> q;
    
    vector <vector <int>> arr1[n];
    int i = 0;
    while(n >= i + 1)
    {
        int a, e;
        cin >> a;
        arr1[i][a];
        for(int j = 0; j < a; j++)
        {
            cin >> e;
            arr1[i][j].push_back(e);
        }
    }
    
    return 0;
}

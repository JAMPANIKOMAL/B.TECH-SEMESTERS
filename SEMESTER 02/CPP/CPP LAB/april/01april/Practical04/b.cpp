//Wite a C++ program to perform 3x3 matrix multiplication.

#include<iostream>
using namespace std;

int main()
{
    cout << endl;
    int i, j, k, a[3][3], b[3][3], c[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    
    //SCANNING MATRIX A.
    cout << "Enter values of matrix a: " << endl;
    for(i=0; i<3; i++) 
    {
        for(j=0; j<3; j++)
        {
            cout << "Enter the value of a" << i << j << ":";
            cin >> a[i][j];
        }
    }
    cout << endl;

    //PRINTING MATRIX A.
    cout << "Matrix a is: " << endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //SCANNING MATRIX B.
    cout << "Enter values of matrix b: " << endl;
    for(i=0; i<3; i++) 
    {
        for(j=0; j<3; j++)
        {
            cout << "Enter the value of b" << i << j << ":";
            cin >> b[i][j];
        }
    }
    cout << endl;

    //PRINTING MATRIX B.
    cout << "Matrix b is: " << endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //MULTIPLYING MATRIX a AND b.
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            for(k=0; k<3; k++)
            {
              c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    //PRINTING MATRIX C.
    cout << "Matrix c is: " << endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

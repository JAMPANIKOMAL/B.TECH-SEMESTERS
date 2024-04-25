//1. W.A.P. to read a matrix of size min from the keyboard and display the same on the screen using function.

#include <iostream>
using namespace std;

void create_matrix(int * b, int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << "a" << i << j << ": ";
            cin >> *((b + i * columns) + j);
        }
    }
}

void print_matrix(int * b, int rows, int columns)
{
    cout << "Your Array is: " << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << "a" << i << j << ":" << *((b + i * columns) + j) << endl;
        }
    }
}

int main()
{
    cout << endl;
    int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    int a[rows][columns];

    create_matrix((int *)a, rows, columns);
    cout << endl;

    print_matrix((int *)a, rows, columns);
    cout << endl;

    return 0;
}
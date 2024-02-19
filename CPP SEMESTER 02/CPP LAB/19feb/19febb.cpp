//PROGRAM TO PRINT SQUARE PATTERN.
//USED printf instead of cout.
#include <iostream>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        if (i==0 || i==n-1)
            {
                for (int k=0; k<n; k++)
                {
                    printf("* ");
                }
                printf("\n");
            }
        else
        {
            for (int j=0; j<n; j++)
            {
                if (j==0 || j==n-1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
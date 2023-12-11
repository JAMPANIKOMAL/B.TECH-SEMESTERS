//Code to print values of arrays in row wise mapping descending order
#include<stdio.h>
int main()
{
    int j,i,a[3][3];
    printf("Enter your values: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", &a[i][j] );
        }
    }
    for(i=2;i>=0;i--)
    {
        for(j=2;j>=0;j--)
        {
            printf("%d", a[i][j] );
        }
    }
}

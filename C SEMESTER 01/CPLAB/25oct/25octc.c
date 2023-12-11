//Code to print values of arrays in column wise mapping ascending order
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
    /* for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d", a[i][j] );
        }
        printf("\n");
    } */
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d", a[j][i] );
        }
    }
}

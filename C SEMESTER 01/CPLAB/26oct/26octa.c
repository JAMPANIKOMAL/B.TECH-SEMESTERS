//Code to print matrix multiplication arrays.
#include<stdio.h>
int main()
{
    int k,j,i,a[3][3],b[3][3],c[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    printf("Enter your values of matrix a: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", &a[i][j] );
        }
    }

    printf("Enter your values of matrix b: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
         for(k=0;k<3;k++)
            {
              c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ", a[i][j] );
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ", b[i][j] );
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ", c[i][j] );
        }
        printf("\n");
    }
}

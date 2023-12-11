//Code to initialise and print 3d array.
#include<stdio.h>
int main()
{
    int noa,r,c,i,j,k;
    printf("For a 3d array a: \n");
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the number of number of arrays: ");
    scanf("%d", &noa);
    int a[noa][r][c];
    printf("Enter the values of 3d matrix: \n");
    for(k=0;k<noa;k++)
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }
    
    for(k=0;k<noa;k++)
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }  
    return 0; 
}
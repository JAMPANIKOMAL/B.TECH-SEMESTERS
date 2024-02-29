//Write a c programm to create n number of variables using malloc or calloc and print sum of it. n will be provided by user.
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int n;
    printf("\nEnter the number of variables n: ");
    scanf("%d", &n);
    int *aptr;
    aptr=(int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        printf("Enter the value of variable %d: ", i+1);
        scanf("%d", &*(aptr+i));
    }
    for (int i=0; i<n; i++)
    {
        printf("The value of variable %d is %d.\n", i+1, *(aptr+i));
    }
    return 0;

}
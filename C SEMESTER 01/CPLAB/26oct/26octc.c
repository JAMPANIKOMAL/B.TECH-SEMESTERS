//Write a c programm to delete an element from a user defined 1d array. Array size and elements are user defined.
#include <stdio.h>
int main()
{
    int s,p;
    printf("Enter the size of 1d array: \n");
    scanf("%d", &s);
    int i,a[s];
    printf("Enter the values of 1d array: \n"); 
    for(i=0;i<s;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Your 1d array is: \n");
    for(i=0;i<s;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter the index of the value in 1d array to be deleted: \n");
    scanf("%d", &p);
    for(i=p;i<s-1;i++)
    {
        a[i]=a[i+1];
    }
    printf("Your new 1d array is: \n");
    for(i=0;i<s;i++)
    {
        printf("%d ", a[i]);
    }

}
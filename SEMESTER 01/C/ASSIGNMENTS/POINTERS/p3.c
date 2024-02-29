//Create a program to find the sum of elements in an array using pointers.
#include <stdio.h>
int main ()
{
    int size;
    printf("\nEnter the size of the 1d array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the values of 1d array:\n");
    for (int i=0; i<size; i++)
    {
        printf("Enter the value of elemnt %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Your 1d array is: ");
    printf("{");
    for (int i=0; i<size-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for (int i=size-1; i<size; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n");
    int *ap=a;
    int sum=0;
    for (int i=0; i<size; i++)
    {
        sum=sum + *(ap+i);
    }
    printf("The sum of all the elements in the given 1d array is %d.\n", sum);


    return 0;
    
}
    
    

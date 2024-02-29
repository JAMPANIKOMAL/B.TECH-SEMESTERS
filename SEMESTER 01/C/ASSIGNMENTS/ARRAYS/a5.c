//Write a program to find the second largest element in an array.
#include <stdio.h>
#include <limits.h>
int main ()
{
    int size;
    int i=0;
    printf("\nEnter the size of 1d array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the values of 1d array: \n");
    //Scanning values of 1d array from user.
    for (i=0; i<size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &a[i]);
    }
    //Printing 1d array.
    printf("Your 1d array is: ");
    printf("{");
    for (i=0; i<size-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for (i=size-1; i<size; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n");
    //Find second largest value.
    int max1=INT_MIN, max2=INT_MIN+1;
    for (i=0; i<size; i++)
    {
        if (a[i]>=max1)
        {
            max2=max1;
            max1=a[i];
        }
    }
    printf("The second largest element in 1d array is %d.\n", max2);
    
}
//C program to reverse the elements of an array.
//NOT WORKING
#include <stdio.h>

int main ()
{
    int size;
    int i=0;
    printf("\nEnter the size of your 1d array: ");
    scanf("%d", &size);
    int a[size];

    //Scanning values of 1d array from user.
    printf("Enter the values of 1d array: \n");
    for (i=0; i<size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &a[i]);
    }

    //Printing 1d array.
    printf("\nYour 1d array is: ");
    printf("{");
    for (i=0; i<size-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for (i=size-1; i<size; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n\n");

    //Reversing 1d array.
    int b[size];
    for (i=0; i<size; i++)
    {
        b[i]=a[size-1-i];
    }

    //Copying b to a. Using for loop. Can use other methods too.
    b[size];
    for (i=0; i<size; i++)
    {
        a[i]=b[i];
    }

    //Printing new 1d array.
    printf("Your Reversed 1d array is: ");
    printf("{");
    for (i=0; i<size-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for (i=size-1; i<size; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n\n");
}
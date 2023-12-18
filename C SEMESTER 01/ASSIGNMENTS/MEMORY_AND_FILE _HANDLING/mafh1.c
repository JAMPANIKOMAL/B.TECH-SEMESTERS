//Explore the concept of dynamic memory allocation using malloc() and free().
#include <stdio.h>
#include <stdlib.h> 
int main()
{
    int *a; // This pointer will hold the base address of the block created.
    int size, i=0;
 
    // Getting the size of the 1d array.
    printf("\nEnter the size of the 1d array: ");
    scanf("%d",&size);
 
    // Dynamically allocating memory using malloc().
    a = (int*)malloc(size * sizeof(int));
 
    // Scanning elements of the 1d array.
    for (i=0; i<size; i++) 
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &a[i]);
    }

    // Printong the elements of the 1d array.
    printf("Your 1d array is: {");
    for(i=0; i<size-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for(i=size-1; i<size; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n");
    free(a);
 
 
    return 0;
}

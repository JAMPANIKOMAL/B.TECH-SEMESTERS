//C program to print the dupilcate elements in an array.
//NOT WORKING.
#include <stdio.h>
#include <stdlib.h>

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

    int b[size];

    for(i = 0; i < size; i++)
    {
        int count = 0;
        for(int j = 0; j < size; j++)
        {
            if(a[i] == a[j])
            {
                count = count + 1;
            }
        }
        if(count != 0)
        {
            b[i] == 1;
        }
        else
        {
            b[i] == 0;
        }
    }
    int sum = 0;
    for(i = 0; i < size; i++)
    {
        sum = sum + b[i];
    }

    // int a1 = 0;
    // int *c = (int*)malloc(0 * sizeof(int));
    
    // for(i = 0; i < size; i++)
    // {
    //     int flag = 1;
    //     for(int k = 0; k <  sizeof(c) / sizeof(c[0]); k++)
    //     {
    //         if(c[k] == b[i])
    //         {
    //             flag == 0;
    //         }
    //     }
    //     if(flag == 1)
    //     {
    //         a1 = a1+1;
    //         c = (int*)realloc(c, a1 * sizeof(int));
    //         c[a1-1] = b[i];
    //     }
    // }

    // printf("Duplicate elements are: ");
    // for(int j = 0; j < sizeof(c) / sizeof(c[0]); j++)
    // {
    //     printf("%d ", c[j]);
    // }
    // printf("\n");

    return 0;
}



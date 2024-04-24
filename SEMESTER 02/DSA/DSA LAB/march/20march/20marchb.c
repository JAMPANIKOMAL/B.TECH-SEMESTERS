//C program to print the dupilcate elements in an array.
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

    //SORTING
    for(int j=0; j<=size; j++)
    {
        for(int temp, k=0; k<=size-2; k++)
        {
            if (a[k] >= a[k+1])
            {
                temp=a[k];
                a[k]=a[k+1];
                a[k+1]=temp;
            }
        }
    }

    int b[size];
    for(i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(a[i] == a[j])
            {
                b[i] = 1;
            }
            else
            {
                b[i] = 0;
            }
        }
    }

    int sum = 0;
    for(i = 0; i < size; i++)
    {
        sum = sum + b[i];
    }
    printf("%d", sum);
    // int c[size];

    // int k = 0;
    // for(i = 0; i < size; i++)
    // {
    //     for(int j = i+1; j < size; j++)
    //     {
    //         if(a[i] == a[j])
    //         {
    //             b[k] = a[i];
    //             k++;
    //         }
    //     }
    // }
    // b[k] = a[size-1]+1;

    // printf("\nYour 1d array is: ");
    // printf("{");
    // for (i=0; i<size-1; i++)
    // {
    //     printf("%d, ", b[i]);
    // }
    // for (i=size-1; i<size; i++)
    // {
    //     printf("%d", b[i]);
    // }
    // printf("}\n\n");

    return 0;
}
//Write a C program to implement Bubble Sort.

#include <stdio.h>

void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n-1; i++) 
    {
        for (j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    printf("\nEnter the size of 1d array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the values of 1d array: \n");
    for (int i=0; i<size; i++)
    {
        printf("Enter the value of element %d: ", i);
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

    bubbleSort(a, size);

    printf("Sorted array is: ");
    printf("{");
    for (int i=0; i<size-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for (int i=size-1; i<size; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n\n");

    return 0;
}



//Write a C program to implement Selection Sort.

#include <stdio.h>

void swap(int* xp, int* yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) 
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
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

    selectionSort(a, size);

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



//Write a C program to implement Quick Sort.

#include <stdio.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(a, 0, size - 1);

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



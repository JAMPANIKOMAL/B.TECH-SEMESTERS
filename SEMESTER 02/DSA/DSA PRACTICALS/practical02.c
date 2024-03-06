// Write a C program to implement Linear Search and Binary Search.

#include <stdio.h>
#include <stdlib.h>

int linear_search(int a[], int size, int x);
int binary_search(int a[], int x, int low, int high);
void display(int a[], int size);

int main()
{
    int size;
    printf("\nEnter the Size of Array: ");
    scanf("%d", &size);
    int array[size];
    printf("\nEnter the Elements of Array are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &array[i]);
    }

    int choice;
    while (1)
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1 --> To Search Element using Linear Search.");
        printf("\n2 --> To Search Element using Binary Search.");
        printf("\n3 --> To Display elements of the Array.");
        printf("\n4 --> To Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("\nEnter the element to be searched using Linear Search: ");
                int element;
                scanf("%d", &element);
                int index = linear_search(array, size, element);
                if (index == -1)
                {
                    printf("%d is not present in the Array.\n", element);
                }
                else
                {
                    printf("%d is present at the Index %d in the Array.\n", element, index);
                }
                break;
            }
            case 2:
            {
                printf("\nEnter the element to be searched using Binary Search: ");
                int element;
                scanf("%d", &element);
                int index = binary_search(array, element, 0, size-1);
                if (index == -1)
                {
                    printf("%d is not present in the Array.\n", element);
                }
                else
                {
                    printf("%d is present at the Index %d in the Array.\n", element, index);
                }
                break;
            }
            case 3:
            {
                display(array, size);
                break;
            }
            case 4:
            {
                printf("\n");
                exit(1);
                break;
            }
            default:
            {
                printf("\nInvalid choice.");
                printf("\n");
                break;
            }
            }
    }

    return 0;
}

int linear_search(int a[], int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

int binary_search(int a[], int x, int low, int high)
{
    int mid = low + (high - low) / 2;
    if (a[mid] == x)
    {
        return mid;
    }
    else if (x < a[mid])
    {
        return binary_search(a, x, low, mid - 1);
    }
    else
    {
        return binary_search(a, x, mid + 1, high);
    }
}

void display(int a[], int size)
{
    printf("\nElements of Array are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
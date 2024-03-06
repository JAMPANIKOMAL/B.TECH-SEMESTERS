//Write a C program to implement DMA using malloc or calloc function.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = NULL;
    int choice;
    while (1)
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1 --> To allocate memory using malloc.");
        printf("\n2 --> To allocate memory using calloc.");
        printf("\n3 --> To Free the memory allocated.");
        printf("\n4 --> To Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int size;
                printf("\nEnter the Size of Array: ");
                scanf("%d", &size);
                printf("\nAllocating memory using malloc: ");
                array = (int *)malloc(size * sizeof(int));
                if (array == NULL) 
                {
                    printf("\nMemory not allocated.\n");
                    exit(0);
                }
                else 
                {
                    printf("\nMemory successfully allocated using malloc.\n");
                }
                printf("\nEnter the Elements of Array are:\n");
                for (int i = 0; i < size; i++)
                {
                    printf("Element %d: ", i);
                    scanf("%d", &array[i]);
                }
                printf("\nElements of Array are: \n");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");

                break;
            }
            case 2:
            {
                int size;
                printf("\nEnter the Size of Array: ");
                scanf("%d", &size);
                printf("\nAllocating memory using calloc: ");
                array = (int *)calloc(size, sizeof(int));
                if (array == NULL) 
                {
                    printf("\nMemory not allocated.\n");
                    exit(0);
                }
                else 
                {
                    printf("\nMemory successfully allocated using calloc.\n");
                }
                printf("\nEnter the Elements of Array are:\n");
                for (int i = 0; i < size; i++)
                {
                    printf("Element %d: ", i);
                    scanf("%d", &array[i]);
                }
                printf("\nElements of Array are: \n");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            case 3:
            {
                if(array != NULL)
                {
                    free(array);
                    printf("\nMemory successfully freed.\n");
                }
                else
                {
                    printf("\nMemory not allocated to be freed.\n");
                }
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
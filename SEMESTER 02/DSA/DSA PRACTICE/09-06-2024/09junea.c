#include <stdio.h>
#include <stdlib.h>

int linear(int[], int, int);  /*Function prototype for performing linear search*/

int main()
{
    int *arr;
    int i, N, k, index;
    printf("Enter the number of elements in the array arr :\n");
    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int)); /*Dynamic allocation of memory for thearray*/
    printf("\nEnter the %d elements of the array arr :\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]); /*Reading array elements*/
    } 
    printf("\nEnter the element to be searched :\n");
    scanf("%d", &k);
    index = linear(arr, N, k); /*Calling linear function*/
    
    /*Printing search results*/
    if (index == -999)
    {
        printf("\nElement %d is not present in array arr[% d]", k, N);
    }
        
    else
    {
         printf("\nElement %d is stored at index location %d in the array arr[%d]", k, index, N);
    }
   
    return 0;
}

int linear(int array[], int size, int num)
{
    int i;
    for (i = 0; i < size; i++) /*Scanning array elements one by one*/
    {
        if (num == array[i])
        {
            return (i); /*Successful Search*/
        }
    } 
        
    if (i == size)
    {
        return (-999); /*Unsuccessful Search*/
    }    
}
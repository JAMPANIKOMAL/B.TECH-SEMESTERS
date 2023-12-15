//Implement programs to find the sum, average, maximum, and minimum values in an array.
#include <stdio.h>
#include <limits.h>
int main()
{
    int size;
    printf("Enter the size of 1d array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the values of 1d array: \n");
    //Scanning values of 1d array from user.
    for (int i=0; i<size; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &a[i]);
    }
    //Printing 1d array.
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
    //Sum of values in 1d array.
    int sum=0;
    for (int i=0; i<=size-1; i++)
    {
        sum=sum+a[i];
    }
    printf("Sum of all the values in the 1d array is %d.\n", sum);
    //Average of values in 1d array.
    float avg = (float)sum/(float)size;
    printf("Average of all the values in array is %f.\n", avg);
    //Maximum value in the 1d array.
    int max=INT_MIN;
    for (int i=0; i<=size-1; i++)
    {
        if (a[i]>=max)
        {
            max=a[i];
        }
    }
    printf("Maximum value in the 1d array is %d.\n", max);
    //Minimum value in the 1d array.
    int min=INT_MAX;  //INT_MAX will allot the minimum value of integer possible in compiler.
    for (int i=0; i<=size-1; i++)  //Instead of initialising i everytime initialise at start.
    {
        if (a[i]<=min)
        {
            min=a[i];
        }
    }  
    printf("Minimum value in the 1d array is %d.\n", min);

    return 0;
}
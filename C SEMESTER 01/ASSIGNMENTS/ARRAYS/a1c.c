//Write programs to manipulate arrays (sorting, searching, insertion, deletion).
//Write a c programm to search an element in 1d array. Array size and elements are user defined.
#include <stdio.h>
int main()
{
    int s, p;
    printf("Enter the size of 1d array: ");
    scanf("%d", &s);
    int i, a[s];
    printf("\n");
    printf("Enter the values of 1d array:\n"); 

    for(i=0; i<s; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
    
    printf("Your 1d array is: \n");

    printf("{");
    for(i=0; i<s-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for(i=s-1; i<s; i++)
    {
        printf("%d", a[i]);
    }
    printf("}");

    printf("\n");

    printf("Enter the number to be searched in 1d array to be deleted: ");
    scanf("%d", &p);

    for(i=0; i<s; i++)
    {
       if (p=a[i])
       {
         printf("%d is in the array.", p);
       }
       else
       {
         printf("%d is not in the array.", p);
       }
    }
            

    return 0;            

}

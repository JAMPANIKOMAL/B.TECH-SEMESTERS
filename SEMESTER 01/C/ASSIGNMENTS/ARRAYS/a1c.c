//Write programs to manipulate arrays (sorting, searching, insertion, deletion).
//Write a c programm to search an element in 1d array. Array size and elements are user defined.
#include <stdio.h>
int main()
{
    int s, p;
    printf("\nEnter the size of 1d array: ");
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
    
    printf("Your 1d array is: ");

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

    printf("\nEnter the number to be searched in 1d array: ");
    scanf("%d", &p);

    //printf("\n");

    int count=0;

    for(int i=0; i<s; i++)
    {
       if (p==a[i])
       {
         printf("%d is in the array.\n", p);
         count=1;
       }
    }

    printf("\n");

    if(count==0)
    {
      printf("%d is not in the array.\n", p);
    }

    printf("\n");      

    return 0;            

}

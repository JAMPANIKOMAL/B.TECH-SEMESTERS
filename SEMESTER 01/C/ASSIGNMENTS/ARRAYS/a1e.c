//Write programs to manipulate arrays (sorting, searching, insertion, deletion).
//Write a c programm to insert an element in 1d array. Array size and elements are user defined.
#include <stdio.h>
int main()
{
    int s, p, m;
    printf("Enter the size of 1d array: ");
    scanf("%d", &s);
    int a[s];
    printf("\n");
   
    if (s!=0)
    {
        printf("Enter the values of 1d array:\n"); 

        for(int i=0; i<s; i++)
        {
            printf("Enter the value of element %d: ", i);
            scanf("%d", &a[i]);
        }
            
        printf("\n");
        printf("Your 1d array is: ");

        printf("{");
        for(int i=0; i<s-1; i++)
        {
            printf("%d, ", a[i]);
        }
        for(int i=s-1; i<s; i++)
        {
            printf("%d", a[i]);
        }
        printf("}");

        printf("\n");
    }
    else
    {
        int a={(int)NULL};
        printf("Your 1d array is: {}\n\n");

    }

    printf("Enter the index where the value should be inserted in 1d array: ");
    scanf("%d", &p);

    while (p>s)   
    {
        printf("Enter correct index value.\n");
        printf("Enter the index where the value should be inserted in 1d array: ");
        scanf("%d", &p);

    } 

    printf("Enter the value to be inserted in 1d array: ");
    scanf("%d", &m);
    printf("%n");

    s=s+1;
    a[s];

    for(int i=s-1; p<i; i--)
    {
        a[i]=a[i-1];
    }

    a[p]=m;
    

    printf("\nYour new 1d array is: ");

    printf("{");
    for(int i=0; i<s-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for(int i=s-1; i<s; i++)
    {
        printf("%d", a[i]);
    }
    printf("}");

    printf("\n");

}

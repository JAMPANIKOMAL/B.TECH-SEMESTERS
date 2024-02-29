//Write programs to manipulate arrays (sorting, searching, insertion, deletion).
//Write a c programm to sort elements of 1d array in descensing order. Array size and elements are user defined.
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

    for(int j=0, count; j<=s; j++)
    {
        //if(count!=0)
        //{
            for(int temp=0, count=0, k=0; k<=s-2; k++)   //s-2 because s -1 is last element in array starts from zero and s-2 is last but one. COde is correct in ascending order because the value in s-1+1 = s is bigger than s-2 value.
            {
                if (a[k] <= a[k+1])
                {
                    temp=a[k+1];
                    a[k+1]=a[k];
                    a[k]=temp;
                    count=1;
                }
            }
       /* }
        else
        {
            break;
        }*/
        
    }
    printf("\n");
            

    printf("Your new 1d array is: ");

    printf("{");
    for(i=0; i<s-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for(i=s-1; i<s; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n");


    return 0;            

}

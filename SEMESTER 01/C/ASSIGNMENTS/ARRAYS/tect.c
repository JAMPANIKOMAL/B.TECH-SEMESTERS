//Write programs to manipulate arrays (sorting, searching, insertion, deletion).
//Write a c programm to sort elements of 1d array in ascensing order. Array size and elements are user defined.
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
    printf("{%d, %d, %d ,%d}",a[i],a[i+1],a[i+2],a[i+3]);
    
    printf("\n");

    for(int j=0, count; j<=s; j++)
    {
        if(count!=0)
        {
            for(int temp, count=0, k=0; k<=s-2; k++)
            {
                if (a[k] >= a[k+1])
                {
                    temp=a[k];
                    a[k]=a[k+1];
                    a[k+1]=temp;
                    count=1;
                }
            }
        }
        else
        {
            break;
        }
        
    }
    printf("\n");
            

    printf("Your new 1d array is: \n");

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


    return 0;            

}

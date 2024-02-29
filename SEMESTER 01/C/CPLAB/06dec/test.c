//Write a C programm to find maximum and minimum from an array using a single function.
//Method 2.
#include <stdio.h>
//void array_maxnmin(int b[]);
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("%d\n", sizeof(a)/sizeof(a[0]));
    /*for(int i=0; i<n; i++)
   {
        printf("Enter the value of element %d of array: ", i+1);
        scanf("%d", &a[i]);
    }
    //array_maxnmin(a);
    
    return 0;*/
}
/*void array_maxnmin(int b[])
{
    int max=0, min;
    int len=sizeof(b);   
    for(int i=0; i<len; i++)
    {
        if(max <= b[i])
        {
            max=b[i];
        }
    }
    printf("Maximum element of given array is %d.\n", max);
    

    for(int i=0; i<len; i++)
    {
        if(min >= b[i])
        {
            min=b[i];
        }
    }
    printf("Minimum element of given array is %d.\n", min);
}*/
//Create a program to generate the Fibonacci series up to a specified number of terms using a loop.
#include <stdio.h>
int main()
{
    int m, n1=0, n2=1, n3;
    printf("Enter your number m: ");
    scanf("%d", &m);

    for(int i=0; i<=m; i++)
    {
        printf("%d ", n1);
        if(m==0)
        {
            n1=0;
        }
        else if(m==1)
        {
            n1=1;
        }
        if(m>1)
        {
            n3=n2+n1;
            n1=n2;
            n2=n3;
        }
        
    }
    printf("\n");

    return 0;
}

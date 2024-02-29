//Write a program that calculates the power of a number using a user-defined function.
#include <stdio.h>
#include <math.h>
int print_power(int g, int h);
int a=3;

int main()
{
    int m, n;
    printf("\nEnter your base number m: ");
    scanf("%d", &m);
    printf("Enter your power n: ");
    scanf("%d", &n);
    
    if(m==0 && n==0)
    {
        printf("0 raised to the power 0 is undefined.\n");
    }
    else
    {
        printf("%d raised to the power %d is %d.\n", m, n, print_power(m,n));
    }

    return 0;
}

int print_power(int g, int h)
{
    for (; h>=2; h--)
    {
        g=g*g;
    }
    return g;
}
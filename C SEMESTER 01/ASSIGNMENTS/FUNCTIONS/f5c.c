//Implement recursive functions for Fibonacci series, factorial, and any other suitable problem.
//Write a program that calculates the power of a number using a user-defined recursive function.
#include <stdio.h>
int print_power(int g, int h);

int main()
{
    int m, n;
    printf("Enter your base number m: ");
    scanf("%d", &m);
    printf("Enter your power n: ");
    scanf("%d", &n);
    
    if(m==0 && n==0)
    {
        printf("0 raised to the power 0 is undefined.\n");
    }
    else
    {
        printf("%d raised to the power %d is %d\n.", m, n, print_power(m,n));
    }

    return 0;
}

int print_power(int g, int h)
{
    if (h==0)
    {
        return 1;
    }
    else if(g==0)
    {
        return 0;
    }
    else
    {
        return g*print_power(g,h-1);
    }
}
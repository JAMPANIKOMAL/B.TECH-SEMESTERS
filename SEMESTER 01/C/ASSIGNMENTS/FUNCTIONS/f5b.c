//Implement recursive functions for Fibonacci series, factorial, and any other suitable problem.
//Create a function to calculate the factorial of a number using recursive functions.
#include <stdio.h>
int print_factorial(int g);

int main()
{
    int n;
    printf("\nEnter your number n: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d.\n", n, print_factorial(n));

    return 0;
}

int print_factorial(int g)
{
    if (g==1)
    {
        return 1;
    }
    else if (g==0)
    {
        return 1;
    }
    else
    {
        return g*print_factorial(g-1);
    }
        
}
//C code to print factorial of a number using recursion.
#include <stdio.h>
int print_factorial(int g);
int main()
{
    int n;
    printf("Enter your number n: ");
    scanf("%d", &n);
    printf("%d", print_factorial(n));
    return 0;
}

int print_factorial(int g)
{
    if (g==1)
    {
        return g;
    }
    else if (g==0)
    {
        return 1;
    }
    else
    {
        return g=g*print_factorial(g-1);
    }
        
}
//Implement recursive functions for Fibonacci series, factorial, and any other suitable problem.
//C code to print fibonacci series of a number using recursion.
#include <stdio.h>
int print_fibonacci(int g);

int main()
{
    int n, i;
    printf("Enter your number n: ");
    scanf("%d", &n);

    for(i=0; i<=n; i++)
    {
        printf("%d ", print_fibonacci(i));
    }
    printf("\n");
    
    return 0;
}


int print_fibonacci(int g)
{
    if (g==0)
    {
        return 0;
    }
    else if (g==1)
    {
        return 1;
    }
    else
    {
       return print_fibonacci(g-1) + print_fibonacci(g-2);
    }
        
}
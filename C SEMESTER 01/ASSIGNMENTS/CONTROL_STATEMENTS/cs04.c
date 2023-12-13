//Implement a program to find the factorial of a number using iterative approaches.
#include <stdio.h>
int main()
{
    int m, n;
    printf("Enter your number n: ");
    scanf("%d", &n);
    m=n;

    if(n==0)
    {
        printf("Factorial of 0 is 1.\n");
    }
    else
    {
        for(int i=n-1; 1<=i; i--)
        {
            n=n*i;
        }
        printf("Factorial of %d is %d.\n", m, n);
    }

    return 0;
}

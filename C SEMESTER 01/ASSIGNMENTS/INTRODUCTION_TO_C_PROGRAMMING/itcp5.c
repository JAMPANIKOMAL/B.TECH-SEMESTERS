//Create a simple calculator program that performs addition, subtraction, multiplication, and division based on user choice.
#include <stdio.h>
int main()
{
    int a, b, n;
    printf("Enter your first number: ");
    scanf("%d", &a);
    printf("Enter your second number: ");
    scanf("%d", &b);
    printf("Enter 0 for Sum, 1 for Difference, 2 for Product and 3 for Division of your numbers. ");
    scanf("%d", &n);
    if(n==0)
    {
        printf("%d", a+b);
    }
    else if(n==1)
    {
        printf("%d", a-b);
    }
    else if(n==2)
    {
        printf("%d", a*b);
    }
    else if(n==3)
    {
        printf("%d", a/b);
    }
    else
    {
        printf("Enter a valid number given to perform operations.\n");
    }

    return 0;
}
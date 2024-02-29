//Write a program to determine if a number is even or odd using if-else statements.
#include <stdio.h>
int main()
{
    int num;
    printf("Enter your number: ");
    scanf("%d", &num);
    
    if (num % 2 == 0)
    {
        printf("%d is an even number.\n", num);
    }
    else
    {
        printf("%d is a odd number.\n", num);
    }

    return 0;
}
//Implement a calculator program using switch-case statements.
#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter your first number a: ");
    scanf("%d", &a);
    printf("Enter your second number b: ");
    scanf("%d", &b);
    printf("Enter 0 for Addition, 1 for Subtraction, 2 for multiplication and 3 for Division.\n");
    scanf("%d", &c);
    
    switch(c)
    {
        case 0:
        printf("The sum of %d and % d is %d.\n", a, b, a+b);
        break;
        case 1:
        printf("The difference of %d and %d is %d.\n", a, b, a-b);
        break;
        case 2:
        printf("The product of %d and %d is %d.\n", a, b, a*b);
        break;
        case 3:
        printf("The division of %d and %d is %d.\n", a, b, a/b);
        break;
        default:
        printf("Enter the correct value.\n");
        break;
    }

    return 0;
}
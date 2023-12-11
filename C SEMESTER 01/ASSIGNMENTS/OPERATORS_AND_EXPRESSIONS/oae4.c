//Create a program that swaps two numbers using arithmetic and bitwise operators.
#include <stdio.h>
int main()
{
    int a, b, c, s;
    printf("Enter your first number a: ");
    scanf("%d", &a);
    printf("Enter your second number b: ");
    scanf("%d", &b);
    printf("a=%d, b=%d\n", a, b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("a=%d, b=%d\n", a, b);
   
    return 0;
}
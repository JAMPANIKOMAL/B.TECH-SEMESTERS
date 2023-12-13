//Write a c program to find greater of the two numbers given by user using function return pointer.
#include <stdio.h>
int * print_greater_pointerfn(int *a, int*b);
int main()
{
    int x, y;
    printf("Enter your first number: ");
    scanf("%d", &x);
    printf("Enter your second number: ");
    scanf("%d", &y);
    printf("The greater of %d and %d is %d.\n", x, y, *print_greater_pointerfn(&x, &y));

    return 0;

}

int * print_greater_pointerfn(int *a, int*b)
{
    if (*a > *b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}
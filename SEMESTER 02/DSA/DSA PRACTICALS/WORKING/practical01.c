// Write a C program to implement Call by Value and Call by Refrence.
//WORKING

#include <stdio.h>

void cbv(int a, int b);
void cbr(int *a, int *b);

int main()
{
    printf("\n");
    int a, b;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("\nBefore swapping a = %d and b = %d\n", a, b);
    cbv(a, b);
    printf("\nAfter swapping using Call By Value, a = %d and b = %d\n", a, b);
    cbr(&a, &b);
    printf("After swapping using Call By Reference, a = %d and b = %d\n\n", a, b);

    return 0;
}

void cbv(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void cbr(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
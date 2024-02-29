//Write a program to swap the given numbers by call by value.
#include <stdio.h>
#include <stdio.h>
void swap_cbv(int g, int h);
int main()
{
    int a, b, c, s;
    printf("Enter your first number a: ");
    scanf("%d", &a);
    printf("Enter your second number b: ");
    scanf("%d", &b);
    printf("a=%d, b=%d\n", a, b);
    swap_cbv(a, b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

void swap_cbv(int g, int h)
    {
        int temp=g;
        g=h;
        h=temp;
        printf("a=%d, b=%d\n", g, h);

    }
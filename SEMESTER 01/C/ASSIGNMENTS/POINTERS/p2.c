//Implement functions to swap values using pointers and without using pointers.
#include <stdio.h>
void swap_cbr(int *g, int *h);
int main()
{
    int a, b;
    printf("\nEnter your first number a: ");
    scanf("%d", &a);
    printf("Enter your second number b: ");
    scanf("%d", &b);
    printf("a=%d, b=%d\n", a, b);
    swap_cbr(&a, &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}

void swap_cbr(int *g, int *h)
    {
        int temp=*g;
        *g=*h;
        *h=temp;
        printf("a=%d, b=%d\n", *g, *h);
        //printf("a=%d, b=%d\n", g, h);
        
    }
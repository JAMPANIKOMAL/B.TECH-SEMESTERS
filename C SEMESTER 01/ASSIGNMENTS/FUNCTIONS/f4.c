//Write a function to find the maximum of three numbers.
#include <stdio.h>
void print_max(int g, int h, int i);
int main()
{
    int a, b, c;
    printf("\nEnter your first number: ");
    scanf("%d", &a);
    printf("Enter your second number: ");
    scanf("%d", &b);
    printf("Enter your third number: ");
    scanf("%d", &c);
    print_max(a, b, c);

    return 0;
}

void print_max(int g, int h, int i)
{
    /*if (g>=h && h>=i)
    {
        printf("The maximum number among %d, %d, %d is %d.\n", g, h, i, g);
    }
    else if (h>=i && i>=g)
    {
        printf("The maximum number among %d, %d, %d is %d.\n", g, h, i, h);
    }
    else if ( i>=g && g>=h)
    {
        printf("The maximum number among %d, %d, %d is %d.\n", g, h, i, i);   
    }*/
    //The problem in above code is it gives wrong output with negative numbers.

    if (g>=h && g>=i)
    {
        printf("The maximum number among %d, %d, %d is %d.\n", g, h, i, g);
    }
    else if (h>=i && h>=g)
    {
        printf("The maximum number among %d, %d, %d is %d.\n", g, h, i, h);
    }
    else if ( i>=g && i>=h)
    {
        printf("The maximum number among %d, %d, %d is %d.\n", g, h, i, i);   
    }
}
//C code to print m raised to power n where m and are user defined.
//Method 2.
#include <stdio.h>
int print_power(int g, int h);
int main()
{
    int m,n;
    printf("Enter your number m: ");
    scanf("%d", &m);
    printf("Enter your number n: ");
    scanf("%d", &n);
    printf("%d", print_power(m,n));
    return 0;
}
int print_power(int g, int h)
{
    if (h==0)
    {
        return 1;
    }
    else
    {
        return g*print_power(g,h-1);
    }
}
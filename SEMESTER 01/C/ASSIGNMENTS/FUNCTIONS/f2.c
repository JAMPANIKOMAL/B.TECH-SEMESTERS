//Develop a program to check if a number is prime or not using a function.
#include <stdio.h>
void check_prime(int g);

int main()
{
    int m, n;
    printf("\nEnter your number: ");
    scanf("%d", &m);
    
    if(m==0)
    {
        printf("0 is neither Prime nor Composite.\n");
    }
    else if(m<0)
    {
        printf("There are no negative prime numbers.\n");
    }
    else
    {
        check_prime(m);
    }

    return 0;
}

void check_prime(int g)
{
    int count=0;

    for(int i=1; i<=g; i++)
    {
        if (g % i==0)
        {
            count=count+1;
        }

    }
    if (count>2)
    { 
        count==0;
        printf("%d is not a Prime number.\n", g);
    }
    else
    {
        count==0;
        printf("%d is a Prime number.\n", g);
    }
}

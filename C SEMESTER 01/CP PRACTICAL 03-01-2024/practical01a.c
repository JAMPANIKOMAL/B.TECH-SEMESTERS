/*Write a C program to check if the entered number is prime or not by using types of user-defined functions with all bellow four techniques. (4 different programs)
1.       No arguments passed and no return value.*/
#include <stdio.h>

void print_poc (void);

int main ()
{
    print_poc ();
}

void print_poc (void)
{
    int n;
    printf("Enter your number: ");
    scanf("%d", &n);
    int count=0;
    if (n==1)
    {
        printf("%d is neither prime nor composite number.", n);
    }
    for (int i=2; i<n && n!=1; i++)
    {
        if (n%i==0)
        {
            count=count+1;
        }
    }
    if(count!=0)
    {
        printf("%d is a composite number.", n);
    }
    else if (count ==0 && n!=1)
    {
        printf("%d is a prime number.", n);
    }
}
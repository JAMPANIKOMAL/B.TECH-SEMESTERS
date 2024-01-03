/*Write a C program to check if the entered number is prime or not by using types of user-defined functions with all bellow four techniques. (4 different programs)
2.       No arguments passed but a return value.*/
#include <stdio.h>

int print_poc (void);

int main ()
{
    int a=print_poc();
    if(a!=0)
    {
        printf("Entered number is a composite number.");
    }
    else if (a ==0)
    {
        printf("%Entered number is a prime number.");
    }
}

int print_poc (void)
{
    int n;
    printf("Enter your number: ");
    scanf("%d", &n);
    int count=0;
    for (int i=2; i<n && n!=1; i++)
    {
        if (n%i==0)
        {
            count=count+1;
        }
    }
    return count;
}
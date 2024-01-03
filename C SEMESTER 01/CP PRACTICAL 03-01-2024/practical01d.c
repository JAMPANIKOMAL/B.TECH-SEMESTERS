/*Write a C program to check if the entered number is prime or not by using types of user-defined functions with all bellow four techniques. (4 different programs)
4.       Argument passed and a return value.*/

#include <stdio.h>

int print_poc (int a);

int main ()
{
    int n;
    printf("Enter your number: ");
    scanf ("%d", &n);
    int a=print_poc(n);
    if (n==1)
    {
        printf("%d is neither prime nor composite number.", n);
    }
    else if(a!=0)
    {
        printf("%d is a composite number.", n);
    }
    else
    {
        printf("%d is a prime number.", n);
    }
}

int print_poc (int a)
{
    int count=0;
    for (int i=2; i<a; i++)
    {
        if (a%i==0)
        {
            count=count+1;
        }
    }
    return count;
}
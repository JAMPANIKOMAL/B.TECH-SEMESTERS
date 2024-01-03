/*Write a C program to check if the entered number is prime or not by using types of user-defined functions with all bellow four techniques. (4 different programs)

3.       Argument passed but no return value.*/
#include <stdio.h>

void print_poc (int a);

int main ()
{
    int n;
    printf("Enter your number: ");
    scanf ("%d", &n);
    //printf("%d", n);
    print_poc (n);
}

void print_poc (int a)
{
    int count=0;
    if (a==1)
    {
        printf("%d is neither prime nor composite number.", a);
    }
    for (int i=2; i<a && a!=1; i++)
    {
        if (a%i==0)
        {
            count=count+1;
        }
    }
    if(count!=0)
    {
        printf("%d is a composite number.", a);
    }
    else if (count ==0 && a!=1)
    {
        printf("%d is a prime number.", a);
    }
}
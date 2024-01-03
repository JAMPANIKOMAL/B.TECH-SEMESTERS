//Write a c program where a positive integer is entered through the keyboard and print the binary equivalent of this number using recursion.
//NOT CORRECT
#include <stdio.h>
void print_binary_equivalent (int a);
int main ()
{
    int n;
    printf("Enter your positive number: ");
    scanf("%d", &n);
    while (n<0)
    {
        printf("Enter your positive number: ");
        scanf("%d", &n);
    }
    printf("%d", n%2);
    print_binary_equivalent (n);

    return 0; 
}

void print_binary_equivalent (int a)
{
    while (a>0) 
    {
        a=a/2;
        print_binary_equivalent (a);
        printf("%d", a%2);
    }
}
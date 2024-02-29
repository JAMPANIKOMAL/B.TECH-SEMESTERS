//Implement a program that removes all occurrences of a specified character from a string.
#include <stdio.h>
//Not working.
int main ()
{
    int size;
    printf("Enter the size of string: ");
    scanf("%d", &size);
    char a[size];
    char del;
    printf("Enter the character to be deleted from the string: ");
    del=getchar();
    printf("%c", del);
}
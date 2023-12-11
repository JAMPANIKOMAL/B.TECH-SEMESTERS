//Create a program to take user input for their name and display a greeting message.
//Method c.
#include <stdio.h>
int main()
{
    char name[99];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s.\n", name);  //Does not print name after space.
    return 0;
}
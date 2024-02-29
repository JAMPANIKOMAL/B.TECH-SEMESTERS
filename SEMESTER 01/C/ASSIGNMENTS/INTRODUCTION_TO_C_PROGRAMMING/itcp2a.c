//Create a program to take user input for their name and display a greeting message.
//Method a.
#include <stdio.h>
int main()
{
    char * name;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s.\n", name);  //Does not print name after space.
    return 0;
}
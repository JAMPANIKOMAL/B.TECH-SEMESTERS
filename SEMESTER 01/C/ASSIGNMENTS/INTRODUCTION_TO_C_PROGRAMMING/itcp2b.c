//Create a program to take user input for their name and display a greeting message.
//Method b.
#include <stdio.h>
int main()
{
    char * name;
    printf("Enter your name: ");
    scanf("%[^\n]s", name);
    printf("Hello, %s.\n", name); //Prints name after space.
    return 0;
}
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
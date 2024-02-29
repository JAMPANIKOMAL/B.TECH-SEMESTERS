//Create programs to perform string manipulation (concatenation, copying).
#include <stdio.h>
#include <string.h>

int main ()
{
    int sizea, sizeb;
    printf("\nEnter the size of your first string: ");
    scanf("%d", &sizea);
    char a[sizea];
    printf("Enter your first string: ");
    scanf("%s", a);
    printf("Enter the size of your second string: ");
    scanf("%d", &sizeb);
    char b[sizeb];
    printf("Enter your second string: ");
    scanf("%s", b);
    printf("Your first string is %s.\n", a);
    printf("Your second string is %s.\n", b);
    //Concatenation of strings.
    strcat(a, b); //Concatenates b at the end of a.
    printf("Concatenation: %s\n", a);
    //Copying strings.
    char c[sizea];
    strcpy(c, b); //Copies a to b.
    printf("Copying: %s\n", c);
    //printf("\n");

    return 0;

}    
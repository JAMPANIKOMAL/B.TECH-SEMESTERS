//Write a program to convert a string to uppercase or lowercase.
#include <stdio.h>
#include <string.h>

int main ()
{
    int sizea;
    printf("Enter the size of your string: ");
    scanf("%d", &sizea);
    char a[sizea];
    printf("Enter your string: ");
    scanf("%s", a);
    // char test='s';
    // test=test-32;
    // printf("%c", test);

    //Converting string to uppercases.
    for (int i=0; i<strlen(a); i++)
    {
        if (97<=a[i]<=122)
        {
            a[i]=a[i]-32;
        }
        else
        {
            continue;
        }
    }
    printf("String with all uppercases: %s\n", a);
    //Converting string to lowercase.
    for (int i=0; i<strlen(a); i++)
    {
        if (65<=a[i]<=90)
        {
            a[i]=a[i]+32;
        }
        else
        {
            continue;
        }
    }
    
    printf("String with all lowercases: %s\n", a);
    

    return 0;
}    

//Write a program to convert a string to uppercase or lowercase.
#include <stdio.h>
#include <string.h>

int main ()
{
    int sizea;
    printf("Enter the size of your string: ");
    scanf("%d", &sizea);
    char astr[sizea];
    printf("Enter your string: ");
    scanf("%s", astr);
    // char test='s';
    // test=test-32;
    // printf("%c", test);

    //Converting string to uppercases.
    for (int i=0; i<strlen(astr); i++)
    {
        if (astr[i]>='a' && astr[i]<='z')
        {
            astr[i]=astr[i]-32;
        }
        else
        {
            continue;
        }
    }
    printf("String with all uppercases: %s\n", astr);

    //Converting string to lowercase.
    for (int i=0; i<strlen(astr); i++)
    {
        if ('A'<=astr[i] || astr[i]<='Z')
        {
            astr[i]=astr[i]+32;
        }
        else
        {
            continue;
        }
    }
    printf("String with all lowercases: %s\n", astr);
    

    return 0;
}    

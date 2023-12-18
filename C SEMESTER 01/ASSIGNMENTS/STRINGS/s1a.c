//Develop a program to check if two strings are anagrams of each other.
//Two words are anagrams of each other if they contain same length, same number of characters and same characters.
//Not verified and not correct.
#include <stdio.h>
#include <string.h>
int main ()
{
    typedef char * string;
    string a;
    string b;
    printf("Enter your first string: ");
    //scanf("%[^\n]s", a);
    gets(a);
    printf("%s", a);
    printf("Enter your second string: ");
    //scanf("%[^\n]s", &b);
    gets(b);
    if (strlen(a) != strlen(b))
    {
        printf("Entered strings are not anagrams of each other.\n");
    }
}
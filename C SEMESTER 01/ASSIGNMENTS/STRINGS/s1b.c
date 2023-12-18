//Develop a program to check if two strings are anagrams of each other.
//Two words are anagrams of each other if they contain same length, same number of characters and same characters.
#include <stdio.h>
#include <string.h>
int main ()
{
    int sizea, sizeb;
    printf("Enter the size of your first string: ");
    scanf("%d", &sizea);
    printf("Enter the size of your first string: ");
    scanf("%d", &sizeb);
    char a[sizea], b[sizeb];
    printf("Enter your first string: ");
    scanf("%s", a);
    printf("Enter your second string: ");
    scanf("%s", b);
    if (strlen(a) != strlen(b))
    {
        printf("Entered strings are not anagrams of each other.\n");
    }
    int count=1;
    for (int i=0; i<strlen(a); i++)
    {
        for (int j=0; j<strlen(b); j++ )
        {
            if (a[i]!=b[j])
            {
               count=0;
               continue; 
            }
            else
            {
                count=1;
                break;
            }
        }
    }
    if (count==1)
    {
        printf("Entered strings are anagrams of each other.\n");   
    }
    else
    {
        printf("Entered strings are not anagrams of each other.\n");
    }

    return 0;


}
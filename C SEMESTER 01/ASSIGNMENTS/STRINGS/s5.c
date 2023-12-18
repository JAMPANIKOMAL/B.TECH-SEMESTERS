//Write a program to count the number of vowels and consonants in a given string.
//Not working.
#include <stdio.h>
#include <string.h>

int main ()
{
    int sizea;
    printf("\nEnter the size of your string: ");
    scanf("%d", &sizea);
    char word[sizea];
    printf("Enter your string: ");
    scanf("%s", word);
    printf("Your string is %s.\n", word);
    int countv=0, countc=0;
    for (int i=0; i<strlen(word); i++)
    {
        if (65<=word[i]<=90 && 97<=word[i]<=122)
        {
            if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U')
            {
                countv=countv+1;
                break;
            }
            else
            {
                countc=countc+1;
            }
        }
    }
    printf("Number of vowels in the given string are %d.\n", countv);
    printf("Number of consonants in the given string are %d.\n", countc);

    return 0;

}    
//Write a program to count the number of vowels and consonants in a given string.
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
        if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U')
        {
            countv=countv+1;
        }
        else if (word[i]=='b' || word[i]=='c' || word[i]=='d' || word[i]=='f' || word[i]=='g' || word[i]=='h' || word[i]=='j' || word[i]=='k' || word[i]=='l' || word[i]=='m' || word[i]=='n' || word[i]=='p' || word[i]=='q' || word[i]=='r' || word[i]=='s' || word[i]=='t' || word[i]=='v' || word[i]=='w' || word[i]=='x' || word[i]=='y' || word[i]=='z')
        {
            countc=countc+1;
        }
        else if (word[i]=='B' || word[i]=='C' || word[i]=='D' || word[i]=='F' || word[i]=='G' || word[i]=='H' || word[i]=='J' || word[i]=='K' || word[i]=='L' || word[i]=='M' || word[i]=='N' || word[i]=='P' || word[i]=='Q' || word[i]=='R' || word[i]=='S' || word[i]=='T' || word[i]=='V' || word[i]=='W' || word[i]=='X' || word[i]=='Y' || word[i]=='Z')
        {
            countc=countc+1;
        }
    }
    printf("Number of vowels in the given string are %d.\n", countv);
    printf("Number of consonants in the given string are %d.\n", countc);

    return 0;

}    
//Implement a program that removes all occurrences of a specified character from a string.
#include <stdio.h>
#include <string.h>

int main ()
{
    int sizea;
    printf("\nEnter the size of your string: ");
    scanf("%d", &sizea);
    char a[sizea];
    printf("Enter your string: ");
    scanf("%s", a);
    printf("Your string is %s.\n", a);
    char b[sizea];
    char del;
    printf("Enter the character to be removed: ");
    scanf(" %c", &del); 
    //printf("%c", del);  //Adding space before %c because scanf is treating the spae in above line as input. Refer https://stackoverflow.com/questions/5109512/problem-in-scanning-character-in-c .
    

    for (int i=0, j=0; i<strlen(a); i++)
    {
        if (a[i]!=del)
        {
            b[j]=a[i];
            j++;
        }
        else
        {
           continue; 
        }
    }
    strcpy(a, b);
    printf("Your new string is %s.\n", a);

    return 0;
}
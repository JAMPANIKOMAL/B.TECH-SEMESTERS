//Implement programs for string reversal.
#include <stdio.h>
#include <string.h>

int main ()
{
    int sizea;
    printf("\nEnter the size of your string: ");
    scanf("%d", &sizea);
    char worda[sizea];
    printf("Enter your string: ");
    scanf("%s", worda);
    printf("Your string is %s.\n", worda);
    char wordb[sizea];
    for (int i=0; i<strlen(worda); i++)
    {
        wordb[i]=worda[strlen(worda)-1-i];
    }
    strcpy(worda, wordb);
    printf("Your reversed string is %s.\n", worda);
    
    return 0;
}
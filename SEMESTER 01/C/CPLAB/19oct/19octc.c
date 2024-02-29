//Program to print * pattern using switch case. 
#include <stdio.h>
int main()
{
	int n,i=1,j=1;
	printf("Enter your number: ");
	scanf("%d", &n); 
    A:
    if(i<=n)
    {
        B:
        if(j<=i)
        {
        printf("*");
        j++;
        goto B;
        }
        j=1;
        printf("\n");
        i++;
        goto A;

    }
    
	return 0;
}


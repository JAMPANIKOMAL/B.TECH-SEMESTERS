//Program to print 1st question * pattern (refer questions in photos)
#include <stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,m,n;
	printf("Enter your number: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		
		for(k=1;k<=i;k++)
		{
			printf("*");
		}
		
	printf("\n");	
	
	}
	
	return 0;
}

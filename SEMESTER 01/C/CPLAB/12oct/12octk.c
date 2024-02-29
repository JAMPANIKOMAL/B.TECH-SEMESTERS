//Program to print pascal triangle of stars
#include <stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,m,n;
	printf("Enter your number: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=(n-i);j++)
		{
			printf(" ");
		}
		
		for(k=1;k<=n-j+1;k++)
		{
			printf("*");
		}
		
		for(m=1;m<=n-j;m++)
		{
			printf("*");
		}
		
		for(l=1;l<=(2*n-1);l++)
		{
			printf(" ");
		}
		
	printf("\n");	
	
	}
	
	return 0;
}

//Program to print 8th question number pattern  
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
			l=l+1;
			printf("%d", l);
		}
		
	printf("\n");	
	
	}
	
	return 0;
}

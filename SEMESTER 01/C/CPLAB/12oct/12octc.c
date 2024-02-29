//Program to print 3rd question number pattern 
#include <stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,m,n;
	printf("Enter your number: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			k=k+1,
			printf("%d", k);
		}
		
	printf("\n");	
	
	}
	
	return 0;
}

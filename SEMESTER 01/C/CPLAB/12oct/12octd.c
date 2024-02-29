//Program to print 4th question * pattern (refer questions in photos)
//1st method
/*#include <stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,m,n;
	printf("Enter your number: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=n;i<=j;j--)
		{
			printf("*");
		}
		
	printf("\n");	
	
	}
	
	return 0;
}*/

//2nd method

#include <stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,m,n;
	printf("Enter your number: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i+1;j++)
		{
			printf("*");
		}
		
	printf("\n");	
	
	}
	
	return 0;
}

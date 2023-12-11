//Program to print 4th question * pattern. 
#include <stdio.h>
int main()
{
	int i, j, n;
	printf("Enter your number: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		for(j=n; i<=j; j--)
		{
			printf("*");
		}
		
	    printf("\n");	
	
	}
	
	return 0;
}
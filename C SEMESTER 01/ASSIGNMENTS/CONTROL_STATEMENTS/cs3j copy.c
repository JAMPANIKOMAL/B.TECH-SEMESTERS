//Program to print 10th question number pattern.
#include <stdio.h>
int main()
{
	int i, j, k, l=0 ,n;
	printf("Enter your number: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i-1; j++)
		{
			printf(" ");
		}
		
		for(k=1; k<=n-i+1; k++)
		{
			l=l+1;
			printf("%d",l);
		}
		
	    printf("\n");	
	
	}
	
	return 0;
}

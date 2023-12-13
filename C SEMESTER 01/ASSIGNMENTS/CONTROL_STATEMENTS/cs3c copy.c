//Program to print 3rd question number pattern.
#include <stdio.h>
int main()
{
	int i, j, k=0, n;
	printf("Enter your number: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{
			k=k+1;
            printf("%d", k);
		}
		
	    printf("\n");	
	
	}
	

	return 0;
}

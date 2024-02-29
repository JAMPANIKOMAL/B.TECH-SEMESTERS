//Practice using loops (while, do-while, for) to print all 10 patterns (triangles, squares, etc.).
//Program to print a square (only outline) of stars using while loop.
#include <stdio.h>
int main()
{
	int i=1, j=1, k=1, m, n;
	printf("\nEnter your number: ");  //Number is length of side of sqaure.
	scanf("%d", &n);
	printf("\n");

	while(i<=n)
	{
		if(i!=1 && i!=n)
		{
			while(j<=n)
			{
			if (j==1 || j==n)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
			j++;
			}
			j=1;
		}
		else
		{
			while(k<=n)
			{
				printf("* ");
				k++;
			}
			k=1;
		}	
		printf("\n");
		i++;
	}
	
	
	return 0;
}

//Practice using loops (while, do-while, for) to print all 10 patterns (triangles, squares, etc.).
//Program to print a rectangle (only outline) of stars using while loop.
#include <stdio.h>
int main()
{
	int i, j, k, m, n;
	printf("Enter width of rectangle: ");
	scanf("%d", &n);
	printf("Enter height of rectangle: ");
	scanf("%d", &m);

	for(i=1; i<=m; i++)
	{
			if(i!=1 && i!=m)
			{
				for(j=1; j<=n; j++)
				{
					if(j==1 || j==n)
					{
						printf("* ");
					}
					else
					{
						printf("  ");
					}
				}
			}	
			else
			{
				for(k=1; k<=n; k++)
				{
					printf("* ");
				}
			}
		printf("\n");
	}	
	
	return 0;
}

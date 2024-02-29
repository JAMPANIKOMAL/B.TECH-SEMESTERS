//Practice using loops (while, do-while, for) to print all 10 patterns (triangles, squares, etc.).
//Program to print a rectangle of stars using for loop.
#include <stdio.h>
int main()
{
	int i, j, m, n;
	printf("\nEnter width of rectangle: ");
	scanf("%d", &n);
	printf("Enter height of rectangle: ");
	scanf("%d", &m);
	printf("\n");
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("* ");
		}
		printf("\n");
	}	
	
	return 0;
}

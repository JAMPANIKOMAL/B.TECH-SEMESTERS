//Practice using loops (while, do-while, for) to print all 10 patterns (triangles, squares, etc.).
//Program to print a triangle pointing downwards of stars using for loop.
#include <stdio.h>
int main()
{
	int i, j, k, l, m, n;
	printf("Enter your number: ");  //Number is height of triangle.
	scanf("%d", &n);

	for(i=n; 1<=i; i--)
	{
		for(j=1; j<=(n-i); j++)
		{
			printf(" ");
		}
		
		for(k=1; k<=n-j+1; k++)
		{
			printf("*");
		}
		
		for(m=1; m<=n-j; m++)
		{
			printf("*");
		}
		
		for(l=1; l<=(2*n-1); l++)
		{
			printf(" ");
		}
		
		printf("\n");	
	}
	

	return 0;
}

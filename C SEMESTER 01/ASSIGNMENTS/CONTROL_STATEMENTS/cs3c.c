//Practice using loops (while, do-while, for) to print all 10 patterns (triangles, squares, etc.).
//Program to print a right angled triangle right angled at right hand side pointing upwards of stars using for loop.
#include <stdio.h>
int main()
{
	int i, j, k, n;
	printf("Enter your number: ");  //Number is height of triangle.
	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=(n-i); j++)
		{
			printf(" ");
		}
		
		for(k=1; k<=n-j+1; k++)
		{
			printf("*");
		}
		
		printf("\n");	
	}
	

	return 0;
}

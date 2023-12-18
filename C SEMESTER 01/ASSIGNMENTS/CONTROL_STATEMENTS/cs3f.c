//Practice using loops (while, do-while, for) to print all 10 patterns (triangles, squares, etc.).
//Program to print a right angled triangle right angled at left hand side pointing upwards of stars using for loop.
#include <stdio.h>
int main()
{
	int i, j, n;
	printf("\nEnter your number: ");  //Number is height of triangle.
	scanf("%d", &n);
	printf("\n");
	for(i=n; 1<=i; i--)
	{
		for(j=1; j<=i; j++)
		{
			printf("*");
		}
		
	    printf("\n");	
	
	}
	
	
	return 0;
}

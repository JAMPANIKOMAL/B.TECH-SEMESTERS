// Write a C program to implement DMA using malloc or calloc function.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int * a = (int *)malloc(4 * sizeof(int));
	a[3] = 0;
	printf("%d", *(a + 3));
	
	int * b = (int *)calloc(4, sizeof(int));
	b[2] = 1;
	printf("%d", *(b + 0));
	printf("%d", *(b + 1));
	printf("%d", *(b + 2));
	
	free(a);
	free(b);
	
	return 0;
}

// Write a C program to implement Call by Value and Call by Refrence.

#include <stdio.h>
#include <conio.h>

void swapbyvalue (int a, int b);
void swapbyreferenece (int * a, int * b);

int main()
{
	int a = 3;
	int b = 4;
	
	printf("\nBefore Swapping: ");
	printf("\na = %d, b = %d", a, b);
	
	
	swapbyvalue(a, b);
	printf("\n\nAfter swapping using call by Value: ");
	printf("\na = %d, b = %d", a, b);
	
	swapbyreferenece(&a, &b);
	printf("\n\nAfter swapping using call by Reference: ");
	printf("\na = %d, b = %d", a, b);
	
	return 0;
}

void swapbyvalue (int a, int b)
{
	int temp = b;
	b = a;
	a = temp;
}

void swapbyreferenece (int * a, int * b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
	
}

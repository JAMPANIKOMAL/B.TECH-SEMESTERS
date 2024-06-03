// Write a C program to implement Selection Sort.

#include <stdio.h>
#include<conio.h>

void selectionsort(int arr[], int size);
void swap(int * a, int * b);

int main()
{
	int a[4] = {3, 2, 1, 4};
	selectionsort(a, 4);
	int i;
	for(i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void selectionsort(int arr[], int size)
{
	int i, j, mindex;
	for(i = 0; i < size - 1; i++)
	{
		mindex = i;
		for(j = i + 1; j < size; j++)
		{
			if(arr[mindex] > arr[j])
			{
				mindex = j;
			}
		}
		swap(&arr[mindex], &arr[i]);
	}
}

void swap(int * a, int * b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

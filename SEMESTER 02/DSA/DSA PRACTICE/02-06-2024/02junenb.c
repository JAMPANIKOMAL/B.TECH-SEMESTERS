// Write a C program to implement insertion Sort.

#include <stdio.h>
#include<conio.h>

void insertionsort(int arr[], int size);

int main()
{
	int a[4] = {3, 2, 1, 4};
	insertionsort(a, 4);
	int i;
	for(i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void insertionsort(int arr[], int size)
{
	int i, j, key;
	for(i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

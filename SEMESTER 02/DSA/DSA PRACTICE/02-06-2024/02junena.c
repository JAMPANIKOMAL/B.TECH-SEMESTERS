// Write a C program to implement Bubble Sort.

#include <stdio.h>
#include<conio.h>

void bubblesort(int arr[], int size);

int main()
{
	int a[4] = {3, 2, 1, 4};
	bubblesort(a, 4);
	int i;
	for(i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void bubblesort(int arr[], int size)
{
	int i, j, temp;
	for(i = 0; i < size - 1; i++)
	{
		for(j = 0; j < size - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}	
}

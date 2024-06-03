// Write a C program to implement Quick Sort.

#include <stdio.h>
#include<conio.h>

void quicksort(int arr[], int low, int high);
void swap(int * a, int * b);
int partition(int arr[], int low, int high);

int main()
{
	int a[4] = {3, 2, 1, 4};
	quicksort(a, 0, 3);
	int i;
	for(i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}

void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int p = partition(arr, low, high);
		quicksort(arr, low, p - 1);
		quicksort(arr, p + 1, high);
	}	
}

void swap(int * a, int * b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int j;
	for(j = low; j < high; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

// Write a C program to implement Linear Search and Binary Search.

#include <stdio.h>
#include <conio.h>

int linear_search(int arr[], int size, int a);
int binary_search(int arr[], int a, int low, int high);

int main()
{
	int a = 4;
	int l, b;
	int arr[4] = {1, 2, 3, 4};
	l = linear_search(arr, 4, a);
	if(l == 1)
	{
		printf("\nFound!");
	}
	else
	{
		printf("\nNot Found!");
	}
	
	b = binary_search(arr, a, 0, 3);
	if(b == 1)
	{
		printf("\nFound!");
	}
	else
	{
		printf("\nNot Found!");
	}
	
	return 0;
}

int linear_search(int arr[], int size, int a)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(arr[i] != a)
		{
			continue;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int binary_search(int arr[], int a, int low, int high)
{
	int mid = low + (high - low) / 2;
	if(arr[mid] == a)
	{
		return 1;
	}
	else if(arr[mid] > a)
	{
		return binary_search(arr, a, low, mid - 1);
	}
	else if(arr[mid] < a)
	{
		return binary_search(arr, a, mid + 1, high);
	}
	else
	{
		return 0;
	}
}

// Write a C program to implement Circular Queue operations using Array.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define max 100
int rear = -1;
int front = -1;
int cqueue[max];

void enqueue(int a);
void dequeue();
void display();

int main()
{
	while(1)
	{
		printf("\nSelect a choice: ");
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your choice: \n> ");
		int choice;
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter the element to be enqueued: \n> ");
				int a;
				scanf("%d", &a);
				enqueue(a);
				break;
			}
			case 2:
			{
				dequeue();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4:
			{
				exit(1);
				break;
			}
			default:
			{
				printf("\nInvalid Choice.\n");
				break;
			}
		}
	}
	
	return 0;
}

void enqueue(int a)
{
	if(front == 0 && front == rear + 1)
	{
		printf("\nQueue is full!");
	}
	else if(front == -1)
	{
		front = rear = 0;
		cqueue[rear] = a;
	}
	else
	{
		rear = (rear + 1) % max;
		cqueue[rear] = a;
	}
}

void dequeue()
{
	if(front == -1)
	{
		printf("\nQueue is empty!");
	}
	else
	{
		front = (front + 1) % max;
		printf("\n%d is dequeued.\n", cqueue[front]);
	}
	printf("\n");
}

void display()
{
	
	if(front == -1)
	{
		printf("\nQueue is empty!\n");
	}
	else
	{
		printf("\nElements of the Queue are: \n");
		int i;
		for(i = front; i <= rear; i++)
		{
			printf("%d ", cqueue[i]);
		}
		printf("\n");
	}
}

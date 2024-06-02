// Write a C program to implement Stack operations using Array.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define max 100
int stack[max];
int top = -1;

void push(int a);
void pop();
void peek();
void display();

int main()
{
	while(1)
	{
		printf("\nSelect:");
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Peek");
		printf("\n4. Display");
		printf("\n5. Exit");
		
		int choice;
		printf("\nEnter your choice: \n> ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				int a;
				printf("\nEnter the element to push: \n> ");
				scanf("%d", &a);
				push(a);
				break;
			}
			case 2:
			{
				pop();
				printf("\n");
				break;
			}
			case 3:
			{
				peek();
				printf("\n");
				break;
			}
			case 4:
			{
				display();
				printf("\n");
				break;
			}
			case 5:
			{
				exit(1);
				printf("\n");
				break;
			}
			default:
			{
				printf("\nInvalid Choice.");
				printf("\n");
				break;
			}
		}
	}
	
	return 0;
}

void push(int a)
{
	if(top == max)
	{
		printf("\nStack Overflow!");
	}
	else
	{
		top++;
		stack[top] = a;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("\nStack Underflow!");
	}
	else
	{
		printf("\n%d is popped.", stack[top--]);
	}
}

void peek()
{
	if(top == -1)
	{
		printf("\nStack Underflow!");
	}
	else
	{
		printf("\n%d is peeked.", stack[top]);
	}
}

void display()
{
	if(top == -1)
	{
		printf("\nStack Underflow!");
	}
	else
	{
		printf("\nElements of the stack are: ");
		int i;
		for(i = top; -1 < i; i--)
		{
			printf("\n%d", stack[i]);
		}
	}
}

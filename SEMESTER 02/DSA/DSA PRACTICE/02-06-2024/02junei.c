// Write a C program to implement Singly Linked List operations - Insert at Begin, Insert at End, Insert at Index, Display, Delete at Begin, Delete at End, Delete at Index.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
	int data;
	struct Node * next;
}node;

node * first = NULL;
node * last = NULL;

void insert_at_begin(int a);
void insert_at_end(int a);
void insert_at_index(int a, int index);
void display();
void delete_at_begin();
void delete_at_end();
void delete_at_index(int index);

int main()
{
	while(1)
	{
		printf("\nSelect a choice: ");
		printf("\n1. Insert at begin");
		printf("\n2. Insert at end");
		printf("\n3. Insert at index");
		printf("\n4. Display");
		printf("\n5. Delete at begin");
		printf("\n6. Delete at end");
		printf("\n7. Delete at index");
		printf("\n8. Exit");
		printf("\nEnter yoyr choice: \n> ");
		int choice;
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter the element to be inserted: \n> ");
				int a;
				scanf("%d", &a);
				insert_at_begin(a);
				break;
			}
			case 2:
			{
				printf("\nEnter the element to be inserted: \n> ");
				int a;
				scanf("%d", &a);
				insert_at_end(a);
				break;
			}
			case 3:
			{
				printf("\nEnter the element to be inserted: \n> ");
				int a;
				scanf("%d", &a);
				printf("\nEnter the index: \n> ");
				int index;
				scanf("%d", &index);
				insert_at_index(a, index);
				break;
			}
			case 4:
			{
				display();
				break;
			}
			case 5:
			{
				delete_at_begin();
				break;
			}
			case 6:
			{
				delete_at_end();
				break;
			}
			case 7:
			{
				printf("\nEnter the index: \n> ");
				int index;
				scanf("%d", &index);
				delete_at_index(index);
				break;
			}
			case 8:
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

void insert_at_begin(int a)
{
	node * ptr = (node *)malloc(sizeof(node));
	if(ptr == NULL)
	{
		printf("\nLinked List is full!");
	}
	else
	{
		ptr -> data = a;
		if(first == NULL)
		{
			first = last = ptr;
			last -> next = NULL;
		}
		else
		{
			ptr -> next = first;
			first = ptr;
		}
	}
}

void insert_at_end(int a)
{
	node * ptr = (node *)malloc(sizeof(node));
	if(ptr == NULL)
	{
		printf("\nLinked List is full!");
	}
	else
	{
		ptr -> data = a;
		if(first == NULL)
		{
			first = last = ptr;
			last -> next = NULL;
		}
		else
		{
			ptr -> next = NULL;
			last -> next = ptr;
			last = ptr;
		}
	}
}

void insert_at_index(int a, int index)
{
	node * ptr = (node *)malloc(sizeof(node));
	if(ptr == NULL)
	{
		printf("\nLinked List is full!");
	}
	else
	{
		ptr -> data = a;
		node * temp;
		int count = 0;
		for(temp = first; temp -> next != NULL; temp = temp -> next)
		{
			count++;
		}
		
		if(index > count)
		{
			printf("\nIndex out of range.");
		}
		else if(index = 0)
		{
			insert_at_begin(a);
		}
		else if(index == count)
		{
			insert_at_end(a);
		}
		else
		{
			int i;
			temp = first;
			for(i = 0; i < index; i++)
			{
				temp = temp -> next;
			}
			ptr -> next = temp -> next;
			temp -> next = ptr; 
		}
	}
}

void display()
{
	node * temp;
	if(first == NULL)
	{
		printf("\nLinked List is empty!");
	}
	else
	{
		printf("\nElements of Linked List are: ");
		for(temp = first; temp != NULL; temp = temp -> next)
		{
			printf("%d ", temp -> data);
		}
	}
	printf("\n");
}

void delete_at_begin()
{
	node * temp;
	if(first == NULL)
	{
		printf("\nLinked List is empty!");
	}
	else
	{
		temp = first;
		first = first -> next;
		free(temp);
	}
	printf("\n");
}

void delete_at_end()
{
	node * temp;
	if(first == NULL)
	{
		printf("\nLinked List is empty!");
	}
	else
	{
		for(temp = first; temp -> next != last; temp = temp -> next) {}
		free(temp -> next);
		temp -> next = NULL;
		last = temp;
	}
	printf("\n");
}

void delete_at_index(int index)
{
	if(first == NULL)
	{
		printf("\nLinked List is empty!");
	}
	else
	{
		node * temp1;
		node * temp2;
		int count = 0;
		
		for(temp1 = first; temp1 -> next != NULL; temp1 = temp1 -> next)
		{
			count++;
		}
		
		if(index > count)
		{
			printf("\nIndex out of range.");
		}
		else if(index == 0)
		{
			delete_at_begin();
		}
		else if(index == count)
		{
			delete_at_end();
		}
		else
		{
			temp1= first;
			int i;
			for(i = 0; i < index - 1; i++)
			{
				temp1 = temp1 -> next;
			}
			
			temp2 = temp1 -> next;
			temp1 -> next = temp2 -> next;
			free(temp2);
		}
	}
}

// Write a C program to implement Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
	int data;
	struct Node * left;
	struct Node * right;
}node;

node * createnode(int a);
node * insert(node * root, int a);
node * search(node * root, int a);
void inorder(node * root);

int main()
{
	node * root =NULL;
	while(1)
	{
		printf("\nSelect a choice: ");
		printf("\n1. Insert");
		printf("\n2. Search");
		printf("\n3. Inorder");
		printf("\n4. Exit");
		printf("\nEnter your choice: \n> ");
		int choice;
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter the element to be inserted: ");
				int a;
				scanf("%d", &a);
				root = insert(root, a);
				break;
			}
			case 2:
			{
				printf("\nEnter the element to be searched: ");
				int a;
				scanf("%d", &a);
				
				if(search(root, a))
				{
					printf("\nFound!");
				}
				else
				{
					printf("\nNot Found!");
				}
				
				break;
			}
			case 3:
			{
				inorder(root);
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

node * createnode(int a)
{
	node * nptr = (node *)malloc(sizeof(node *));
	nptr -> left = NULL;
	nptr -> right = NULL;
	nptr -> data = a;
	return nptr;
}

node * insert(node * root, int a)
{
	if(root == NULL)
	{
		return createnode(a);
	}
	if(a < root -> data)
	{
		root -> left = insert(root -> left, a);
	}
	else if(a > root -> data)
	{
		root -> right = insert(root -> right, a);
	}
	return root;
}

node * search(node * root, int a)
{
	if(root == NULL || root -> data == a)
	{
		return root;
	}
	if(a < root -> data)
	{
		return search(root -> left, a);
	}
	return search(root -> right, a);
	
}

void inorder(node * root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		inorder(root -> left);
		printf("%d ", root -> data);
		inorder(root -> right);
	}
}

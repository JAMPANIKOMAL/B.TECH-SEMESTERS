//Write a C program to implement Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};typedef struct Node node;

node * newnode(int data);
node * insert(node * root, int data);
node * search(node * root, int data);
void inorderdisplay(node * root);

int main()
{
    node * root = NULL;
    int choice;
    while(1)
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1. Insert.");
        printf("\n2. Search.");
        printf("\n3. Display.");
        printf("\n4. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter the data to be inserted: ");
                int data;
                scanf("%d", &data);
                root = insert(root, data);
                break;
            }
            case 2:
            {
                printf("Enter the data to be searched: ");
                int data;
                scanf("%d", &data);
                if (search(root, data) != NULL)
                {
                    printf("data %d found in the BST.\n", data);
                }     
                else
                {
                    printf("data %d not found in the BST.\n", data);
                }
                break;
            }
            case 3:
            {
                printf("Inorder Traversal: ");
                inorderdisplay(root);
                printf("\n");
                break;
            }
            case 4:
            {
                printf("\n");
                exit(1);
                break;
            }
            default:
            {
                printf("Invalid Choice!");
                break;
            }
        }
    }

    return 0;
}

node * newnode(int data)
{
    node * n = (node *)malloc(sizeof(node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL; 
    return n;

}


node * insert(node * root, int data)
{
    if(root == NULL)
    {
        return newnode(data);
    }
    
    if(data < root -> data)
    {
        root -> left = insert(root -> left, data);
    }
    else if (data > root -> data)
    {
        root -> right = insert(root -> right, data);
    }
    else
    {
        return root;
    }
}

node * search(node * root, int data)
{
    if(root == NULL || root -> data == data)
    {
        return root;
    }

    if(data > root -> data)
    {
        return search(root -> right, data);
    }
    else
    {
        return search(root -> left, data);
    }
}

void inorderdisplay(node * root)
{
    if(root == NULL)
    {
        return;
    }

    inorderdisplay(root -> left);
    printf("%d ", root -> data);
    inorderdisplay(root -> right);
}
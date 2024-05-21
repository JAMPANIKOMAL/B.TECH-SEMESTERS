//Write a C program to implement Binary Search Tree.
//UNDERSTAND THIS.

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) 
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int target) 
{
    if (root == NULL || root->data == target)
    {
        return root;
    }
    if (target < root->data)
    {
        return search(root->left, target);
    }
    return search(root->right, target);
}

void inOrderTraversal(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() 
{
    struct Node* root = NULL;
    int choice, data;
    while (1) 
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1. Insert.");
        printf("\n2. Search.");
        printf("\n3. Display.");
        printf("\n4. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
            {
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            }
            case 2:
            {
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(root, data))
                {
                    printf("Value %d found in the BST.\n", data);
                }
                else
                {
                    printf("Value %d not found in the BST.\n", data);
                }
                break;
            }
            case 3:
            {
                printf("In-order Traversal: ");
                inOrderTraversal(root);
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
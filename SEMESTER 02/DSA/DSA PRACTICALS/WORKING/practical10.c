//Write a C program to implement Stack operations using Linked List.

//Queue Using Linked List.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int INFO;
    struct node *NEXT;
};typedef struct node NODE;

NODE * TOP = NULL;

void push(int a);
void pop();
void peek();
void display(NODE * TOP);

int main()
{   
    int choice;
    while(1)
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1. Push.");
        printf("\n2. Pop.");
        printf("\n3. Peek.");
        printf("\n4. Display.");
        printf("\n5. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter the element: ");
                int value;
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                if(TOP == NULL)
                {
                    printf("Stack is empty!\n");
                    break;
                }
                printf("The elements of the Stack are: ");
                display(TOP);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\n");
                exit(1);
                break;
            }
            default:
            {
                printf("\nInvalid choice.");
                printf("\n");
                break;
            }
        }
    }

    return 0;
}

void push(int a)
{
    NODE *PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = a;
    if(TOP == NULL)
    {
        TOP = PTR;
        PTR -> NEXT = NULL;
    }
    else
    {
        NODE * TEMP = TOP;
        while(TEMP -> NEXT != NULL){TEMP = TEMP -> NEXT;}
        TEMP -> NEXT = PTR;
        PTR -> NEXT = NULL;
    }
}

void pop()
{
    if (TOP == NULL)
    {
        printf("\nStack is empty.\n");
    }
    else if(TOP -> NEXT == NULL)
    {
        free(TOP -> NEXT);
        TOP = NULL;
    }
    else
    {
       NODE * TEMP = TOP, * TEMP1;
       while(TEMP -> NEXT != NULL){TEMP1 = TEMP; TEMP = TEMP -> NEXT;}
       TEMP1 -> NEXT = NULL;
       free(TEMP);
    }
}

void peek()
{
    if (TOP == NULL)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        NODE * TEMP = TOP;
        while(TEMP -> NEXT != NULL){TEMP = TEMP -> NEXT;}
        printf("\n%d", TEMP -> INFO);
    }
    printf("\n");
}

void display(NODE * TOP1)
{
    if(TOP1 != NULL)
    {
        display(TOP1 -> NEXT);
        printf("\n%d", TOP1 -> INFO);
    }
}

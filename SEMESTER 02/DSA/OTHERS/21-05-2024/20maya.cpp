//Write a C program to implement Singly Linked List operations - Insert at Begin, Insert at End, Insert at Index, Display, Delete at Begin, Delete at End, Delete at Index.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node * next;
};typedef struct Node node; 

node * first = NULL;
node * last = NULL;

void insertatbegin(int a);
void insertatend(int a);
void insertatindex(int a, int index);
void display();
void deleteatbegin();
void deleteatend();
void deleteatindex(int index);

int main()
{
    int choice;
    while(1)
    {
        printf("\nSelect an option: \n");
        printf("1. Insert at beginning.\n");
        printf("2. Insert at end.\n");
        printf("3. Insert at an index.\n");
        printf("4. Display.\n");
        printf("5. Delete the begining.\n");
        printf("6. Delete the end.\n");
        printf("7. Delete at an index.\n");
        printf("8. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int a;
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                insertatbegin(a);
                break;
            }
            case 2:
            {
                int a;
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                insertatend(a);
                break;
            }
            case 3:
            {
                int a, index;
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                printf("Enter the index: ");
                scanf("%d", &index);
                insertatindex(a, index);
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                deleteatbegin();
                break;
            }
            case 6:
            {
                deleteatend();
                break;
            }
            case 7:
            {
                int index;
                printf("Enter the index: ");
                scanf("%d", &index);
                deleteatindex(index);
                break;
            }
            case 8:
            {
                printf("\n");
                exit(1);
                break;
            }
            default:
            {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }

    return 0;
}

void insertatbegin(int a)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr -> info = a;

    if(first == NULL)
    {
        first = last = ptr;
        ptr -> next = NULL;
    }
    else
    {
        ptr -> next = first;
        first = ptr;
    }
}

void insertatend(int a)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr -> info = a;

    if(first == NULL)
    {
        first = last = ptr;
        ptr -> next = NULL;
    }
    else
    {
        last -> next = ptr;
        ptr -> next = NULL;
        last = ptr;
    }
}

void insertatindex(int a, int index)
{
    node * ptr = (node *)malloc(sizeof(node));
    ptr -> info = a;

    node * temp;

    int count = 0;
    for(temp = first; temp != last; temp = temp -> next)
    {
        count++;
    }

    if(index > count)
    {
        printf("Invalid Index!\n");
    }
    else if (index == 0)
    {
        insertatbegin(a);;
    }
    else if (index == count)
    {
        insertatend(a);
    }

    else if(first == NULL)
    {
        first = last = ptr;
        ptr -> next = NULL;
    }
    else
    {
        temp = first;
        for(int i = 0; i < index - 1; i++)
        {
            temp = temp -> next;
        }
        ptr -> next = temp -> next;
        temp -> next = ptr;
    }
}

void display()
{
    node * temp;

    if (first == NULL)
    {
        printf("\nSingly Linked List is empty.\n");
        return;
    }
    else
    {
       printf("\nThe elements of Linked List are: \n");
       for(temp = first; temp != NULL; temp = temp -> next)
       {
            printf("%d ", temp -> info);
       }
       printf("\n");
    }
}

void deleteatbegin()
{
    if(first == NULL)
    {
        printf("Linked List is empty!");
    }
    else
    {
        node * temp;
        temp = first;
        first = first -> next;
        free(temp);
    }
}

void deleteatend()
{
    if(first == NULL)
    {
        printf("Linked List is empty!");
    }
    else
    {
        node * temp;
        for(temp = first; temp -> next!=last; temp = temp -> next) {}
        free(temp -> next);
        temp -> next = NULL;
        last = temp;
    }
}

void deleteatindex(int index)
{
    if(first == NULL)
    {
        printf("Linked List is empty!");
    }
    else
    {
        node * temp, * temp1;
        int count = 0;
        for(temp = first; temp != last; temp = temp -> next)
        {
            count++;
        }
        if(index > count)
        {
            printf("Invalid index!\n");
        }
        else if(index == 0)
        {
            deleteatbegin();
        }
        else if(index == count)
        {
            deleteatend();
        }
        else
        {
            temp = first;
            for(int i = 0; i < index - 1; i++)
            {
                temp = temp -> next;
            }

            temp1 = temp -> next;
            temp -> next = temp1 -> next;
            free(temp1);
        }
    }
}

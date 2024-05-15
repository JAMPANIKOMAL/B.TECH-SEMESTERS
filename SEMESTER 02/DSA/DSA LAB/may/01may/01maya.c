//Queue Using Linked List.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int INFO;
    struct node *NEXT;
};typedef struct node NODE;

NODE * FRONT = NULL;
NODE * REAR = NULL;

void enqueue(int element);
void dequeue();
void display();

int main()
{
    printf("\n");

    int choice;
    while(1)
    {
        printf("\nSelect an operation from the following to be performed on Queue:");
        printf("\n1 --> Enqueue.");
        printf("\n2 --> Dequeue.");
        printf("\n3 --> Print all the elements.");
        printf("\n4 --> To Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the element to enqueued: ");
                int tbenqueued;
                scanf("%d", &tbenqueued);
                enqueue(tbenqueued);
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

void enqueue(int element)
{
    NODE *PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = element;

    if(PTR == NULL)
    {
        printf("Queue is Full!\n");
        return;
    }

    if (FRONT == NULL)
    {
        FRONT = REAR = PTR;
        PTR -> NEXT = NULL;
        return;
    }
    else
    {
        REAR -> NEXT = PTR;
        PTR -> NEXT = NULL;
        REAR = PTR;
        return;
    }
}

void dequeue()
{
    NODE * TEMP = (NODE *)malloc(sizeof(NODE));

    int value;
    
    if(FRONT == NULL)
    {
        printf("Queue is Empty!");
        return;
    }
    else
    {
        TEMP = FRONT;
        FRONT = TEMP -> NEXT;
        value = TEMP -> INFO;
        free(TEMP);
        printf("\n%d is dequeued.\n", value);
        return;
    }
}

void display()
{
    NODE *PTR;

    if (FRONT == NULL)
    {
        printf("\nQueue is Empty.\n");
        printf("\n");
        return;
    }
    else
    {
       printf("\nThe elements of the Queue are: \n");
       for(PTR = FRONT; PTR != NULL; PTR = PTR -> NEXT)
       {
            printf("%d  ", PTR -> INFO);
       }
       printf("\n");
    }
}
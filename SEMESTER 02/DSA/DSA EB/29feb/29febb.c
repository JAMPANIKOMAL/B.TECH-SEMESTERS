// QUEUE
//INSERT --> INSERTING AN ELEMENT INTO THE QUEUE FROM REAR.
//DELETE --> DELETING OR REMOVING AN ELEMENT FROM THE QUEUE FROM FRONT.
//WE ARE USING ARRAYS TO IMPLEMENT STACKS.

#include <stdio.h>
#include <stdlib.h>

int queue[100];   //DECLARING A QUEUE OF FIXED SIZE 100.
int front = -1;   //DECLARING FRONT AS GLOBAL VARIABLE.
int rear = -1;   //DECLARING REAR AS GLOBAL VARIABLE.
int max = 99;   //DECLARING max AS THE SIZE OF ARRAY.

void insert(int a);
int delete();
void display();

int main()
{   
    int choice;
    while(1)
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1 --> To Insert an element into the queue.");
        printf("\n2 --> To Delete or Remove an element from the queue.");
        printf("\n3 --> To Display elements of the Queue.");
        printf("\n4 --> To Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the value to be Inserted into the queue: ");
                int value;
                scanf("%d", &value);
                insert(value);
                break;
            }
            case 2:
            {
                int deleted;
                deleted = delete();
                if (deleted == -2);
                else
                {
                    printf("\nThe Deleted element from queue is %d.", deleted);
                    printf("\n");
                }
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
                printf("\nInvalid choice.");
                printf("\n");
                break;
            }
        }
    }

    return 0;
}

void insert(int a)
{
    if (front == -1)
    {
        front = rear = front+1;
        queue[front] = a;
        return;
    }
    else if (rear == max)
    {
        printf("\nQueue is full.\n");
        printf("\n");
        return;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = a;
    }
}

int delete()
{
    if (front != -1 && front == rear)
    {
        int i = queue[front];
        front = rear = -1;
        return(i);

    }
    else if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty.\n");
        printf("\n");
        return -2;
    }
    else
    {
       return(queue[front++]);   //RETURN TOP VALUE AND DECREMENTING TOP.
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        printf("\n");
        return;
    }
    else
    {
       printf("\nThe elements of Queue are: \n");
       for(int i = front; i <= rear; i++)
       {
            printf("%d  ", queue[i]);
       }
       printf("\n");
    }
}
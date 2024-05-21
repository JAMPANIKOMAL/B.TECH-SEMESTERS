// Write a C program to implement Circular Queue operations using Array.

#include <stdio.h>
#define maxsize 5
void insert();
void delete1();
void display();
int queue[maxsize];
int rear = -1, front = -1;
int main()
{
    int choice;
start:
    printf("\nSelect a choice from the following: ");
    printf("\n1 --> To Insert an element into the Circular Queue.");
    printf("\n2 --> To Delete an element from the Circular Queue.");
    printf("\n3 --> To Display elements of the Circular Queue.");
    printf("\n4 --> To Exit.");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        insert();
        goto start;
    }
    case 2:
    {
        delete1();
        goto start;
    }
    case 3:
    {
        display();
        goto start;
    }
    case 4:
    {
        break;
    }
    default:
    {
        printf("Enter a valid number");
        goto start;
    }
    }
}
void insert()
{
    int a;
    if ((front == 0 && rear == maxsize - 1) || (front == rear + 1))
    {
        printf("Circluar Queue Underflow");
    }
    else
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % maxsize;
        queue[rear] = a;
    }
}
void delete1()
{
    int b;
    if (front == -1)
    {
        printf("Circular Queue is empty");
    }
    else
    {
        b = queue[front];
        printf("Deleted number: %d", b);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % maxsize;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue elements:\n");
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d\n", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < maxsize; i++)
            {
                printf("%d\n", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d\n", queue[i]);
            }
        }
    }
}
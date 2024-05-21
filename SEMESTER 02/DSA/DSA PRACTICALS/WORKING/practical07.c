// Write a program to insert, delete, display using Queue.

#include <stdio.h>
#define maxsize 5
void insert();
void delete1();
void display();
int queue[maxsize];
int rare = -1, front = 0;
int main()
{
    int choice;
start:
    printf("\nSelect a choice from the following: ");
    printf("\n1 --> To Insert an element into the Queue.");
    printf("\n2 --> To Delete an element from the Queue.");
    printf("\n3 --> To Display elements of the Queue.");
    printf("\n4 --> To Exit.");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insert();
        goto start;
    case 2:
        delete1();
        goto start;
    case 3:
        display();
    case 4:
        break;
        goto start;
    default:
        printf("Enter a valid number");
        goto start;
    }
}
void insert()
{
    int n;
    if (rare == maxsize - 1)
    {
        printf("Queue is overflow\n");
    }
    else
    {
        printf("Enter your element: ");
        scanf("%d", &n);
        rare++;
        queue[rare] = n;
    }
}
void delete1()
{
    int n;
    if (front > rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
        n = queue[front];
        printf("Deleted element: %d\n", n);
        front++;
    }
}
void display()
{
    if (front > rare)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rare; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

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
    else if (index == count)
    {
        insertatend(a);
    }
    else if (index = 0)
    {
        insertatbegin(a);
    }

    if(first == NULL)
    {
        first = last = ptr;
        ptr -> next = NULL;
    }
    else
    {
        temp = first;
        for(int i =0; i < index - 1; i++)
        {
            temp = temp -> next;
        }
        ptr -> next = temp -> next;
        temp -> next = ptr;
    }
}

int main()
{
    
    insertatindex(3, 0);

    return 0;
}
//Write a C program to implement Infix to Postfix conversion using Stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
    int max;
    char * array;
}; typedef struct stack STACK;


void push(STACK *a, int b);
int pop(STACK *a);
int isempty(STACK *a);
int isfull(STACK *a);
int peek(STACK *a);

int main()
{   
    
    return 0;
}

int isempty(STACK *a)
{
    if (a -> top == -1)
    {
        return 1;
    }
    else
    {
       return 0;
    }
}

int isfull(STACK *a)
{
    if (a -> top == (a -> size)-1)
    {
        return 1;
    }
    else
    {
       return 0;
    }
}

void push(STACK *a, int b)
{
    if (isfull(a))
    {
        printf("\nStack is full.\n");
        printf("\n");
        exit(1);
    }
    else
    {
        (a -> top)++;
        a -> array[a -> top]= b;
    }
}

int pop(STACK *a)
{
    if (isempty(a))
    {
        printf("\nStack is empty.\n");
        printf("\n");
        exit(1);
    }
    else
    {
       return(a -> array[a -> top--]);  
    }
}

int peek(STACK *a)
{
    return a -> array[a -> top];
}


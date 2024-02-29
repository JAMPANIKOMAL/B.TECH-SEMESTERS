// STACK
//PUSH --> PUSH ELEMENT TO STACK i.e., PLACES THE DESIRED ELEMENT ON TOP OF STACK.
//POP --> POPS ELEMENT FROM STACK i.e,. REMOVES TOP MOST ELEMENT FROM STACK.
//WE ARE USING ARRAYS TO IMPLEMENT STACKS.

#include <stdio.h>
#include <stdlib.h>

int stack[100];   //DECLARING A STACK OF FIXED SIZE 100.
int top = -1;   //DECLARING TOP AS GLOBAL VARIABLE.
int max = 99;   //DECLARING max AS THE SIZE OF ARRAY.

void push(int a);
int pop();
void display();

int main()
{   
    int choice;
    while(1)
    {
        printf("\nSelect a choice from the following: ");
        printf("\n1 --> To Push an element into the stack.");
        printf("\n2 --> To Pop an element from the stack.");
        printf("\n3 --> To Display elements of the stack.");
        printf("\n4 --> To Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the value to be Pushed into the stack: ");
                int value;
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
            {
                int popped;
                popped = pop();
                printf("\nThe Popped element from stack is %d.", popped);
                printf("\n");
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

void push(int a)
{
    if (top == max)
    {
        printf("\nStack is full.\n");
        printf("\n");
        exit(1);
    }
    else
    {
        top = top + 1;
        stack[top] = a;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
        printf("\n");
        exit(1);
    }
    else
    {
       return(stack[top--]);   //RETURN TOP VALUE AND DECREMENTING TOP.
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
        printf("\n");
        exit(1);
    }
    else
    {
       printf("\nThe elements of stack are: ");
       for(int i = top; i>=0; i--)
       {
            printf("\n%d", stack[i]);
       }
       printf("\n");
    }
}
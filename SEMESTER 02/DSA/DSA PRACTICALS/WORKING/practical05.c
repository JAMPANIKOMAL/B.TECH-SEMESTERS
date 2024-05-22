// Write a C program for infix to postfix conversion using stack.
//WORKING BUT TTU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char * array;
};typedef struct Stack stack;

int precedence(char c);
int isOperator(char c);
int isEmpty(stack *ptr);
int isFull(stack *ptr);
char stackTop(stack *sp);
void push(stack *ptr, char val);
char pop(stack *ptr);
char *infixToPostfix(char *infix);

int main()
{
    char infix[100];
    printf("Enter your infix expression: ");
    scanf("%s", infix);
    printf("Postfix expression is %s\n", infixToPostfix(infix));
    return 0;
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int isEmpty(stack *ptr)
{
    return ptr->top == -1;
}

int isFull(stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

char stackTop(stack *sp)
{
    return sp->array[sp->top];
}

void push(stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push element to stack\n");
    }
    else
    {
        ptr->top++;
        ptr->array[ptr->top] = val;
    }
}

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is underflow! Cannot pop element in stack\n");
        return -1;
    }
    else
    {
        char val = ptr->array[ptr->top];
        ptr->top--;
        return val;
    }
}

char *infixToPostfix(char *infix)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp->array);
    free(sp);
    return postfix;
}


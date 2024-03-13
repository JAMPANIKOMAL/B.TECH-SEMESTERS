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

char * infixtopostfix(char infix[]);
int isoperator(char a);
int precedence(char a);
//char asscociativity();

void push(STACK *a, int b);
int pop(STACK *a);
int peek(STACK *a);
int isempty(STACK *a);
int isfull(STACK *a);

int main()
{   
    printf("\n");
    char infix[100];
    printf("Enter your infix expression: ");
    scanf("%s", infix);
    char * postfix = infixtopostfix(infix);
    printf("%s", postfix);

    return 0;
}

char * infixtopostfix(char infix[])
{
    STACK *a = (STACK *) malloc(sizeof(STACK));
    a -> size = strlen(infix)+1;
    a -> top = -1;
    a -> max = a -> size - 1;
    a -> array = (char *) malloc(a -> size * sizeof(char));

    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if(!(isoperator(infix[i])))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if(precedence(infix[i]) > precedence(peek(a)))
            {
                push(a, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(a);
                j++;
            }
        }
    }
    while (!isempty(a))
    {
        postfix[j] = pop(a);
        j++;
    }
        postfix[j] = '\0';

        return postfix;
}

int isoperator(char a)
{
    char operators[]={'+', '-', '*', '/', '^', '(', ')'};
    for(int i = 0; i < 7; i++)
    {
        if(a == operators[i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int precedence(char a)
{
    if(a == '^')
    {
        return 3;
    }
    else if(a == '*' || a == '/')
    {
        return 2;
    }
    
    else if(a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
//char asscociativity();

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


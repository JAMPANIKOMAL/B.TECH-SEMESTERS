//Write a C program for infix to postfix conversion using stack.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Stack
{
    char * arr;
    int top;
    int max;
}typedef Stack;

int isoperator(char a);
int isempty(Stack S);
int precedence(char a);
char * infixtopostfix(char * infix1);

int main()
{
    char * infix;
    printf("\nEnter your Infix expression: ");
    scanf("%s", infix);
    char * postfix = infixtopostfix(infix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    printf("\n");

    return 0;
}

char * infixtopostfix(char * infix1)
{
    Stack s1;
    char * postfix = (char *)malloc(strlen(infix1) * sizeof(char));

    s1.arr = (char *)malloc(strlen(infix1) * sizeof(char));
    s1.top = -1;
    s1.max = strlen(s1.arr);
    printf("%s", sizeof(s1.arr));

    int i = 0;
    int j = 0;

    while(infix1[i] != '\0')
    {
        if(isoperator(infix1[i]))
        {
            if(isempty(s1))
            {
                s1.arr[s1.top++] = infix1[i];
                i++;
            }
            else
            {
                if(precedence(infix1[i]) > precedence(s1.arr[s1.top]))
                {
                    s1.arr[s1.top++] = infix1[i];
                    i++;
                }
                else
                {
                    postfix[j] = infix1[i];
                    j++;
                    i++;
                }
            }
            
        }
        else
        {
            postfix[j] = infix1[i];
            j++;
            i++;
        }
    }

    while(isempty(s1))
    {
        postfix[j] = s1.arr[s1.top];
        s1.top--;
        j++;
    }
    return postfix;
}

int isoperator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(Stack S)
{
    if(S.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
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
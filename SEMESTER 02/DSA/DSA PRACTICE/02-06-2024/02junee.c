// Write a C program to implement Infix to Postfix conversion using Stack.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define max 100
int stack[max];
int top = -1;

int isoperator(char c);
int precedence(char c);
char * infix_to_postfix(char * c);
int push(char a);
char pop();
char peek();

int main()
{
	printf("\nEnter your infix expression: ");
	char infix[100];
	scanf("%s", infix);
	char * postfix = infix_to_postfix(infix);
	printf("\nPostfix Expression: %s", postfix);
		
	return 0;
}

int isoperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c)
{
	if(c == '^')
	{
		return 3;
	}
	else if(c == '/' || c == '*')
	{
		return 2;
	}
	else if(c == '+' || c == '-')
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

char * infix_to_postfix(char * infix)
{
	char * postfix;
	
	int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(peek()))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }
    
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    
    postfix[j] = '\0';

    return postfix;
}

int push(char a)
{
	if(top == max)
	{
		printf("\nStack Overflow!");
	}
	else
	{
		top++;
		stack[top] = a;
	}
}

char pop()
{
	if(top == -1)
	{
		return 0;
	}
	else
	{
		return stack[top--];
	}
}

char peek()
{
	if(top == -1)
	{
		return 0;
	}
	else
	{
		return stack[top];
	}
}



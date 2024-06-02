#include <stdio.h>

#define MAX_SIZE 100
int top = -1;
char stack[MAX_SIZE];

int is_empty() 
{
  return top == -1;
}

int is_full() 
{
  return top == MAX_SIZE - 1;
}

char push(char item) 
{
  if (is_full()) 
  {
    printf("Stack overflow\n");
    return -1;
  } 
  else 
  {
    stack[++top] = item;
    return 1;
  }
}

char pop() 
{
  if (is_empty()) 
  {
    printf("Stack underflow\n");
    return -1;
  } 
  else 
  {
    return stack[top--];
  }
}

char peek() 
{
  if (is_empty()) 
  {
    printf("Stack is empty\n");
    return -1;
  } 
  else 
  {
    return stack[top];
  }
}

int is_left(char ch) 
{
  return (ch == '{' || ch == '[' || ch == '(');
}

int is_right(char ch) 
{
  return (ch == '}' || ch == ']' || ch == ')');
}

int is_pair(char ch) 
{
  char top_char = peek();
  return (ch == '}' && top_char == '{' || ch == ')' && top_char == '(' || ch == ']' && top_char == '[');
}

int is_bracket_balanced(char *expr) 
{
  int i = 0;
  while (expr[i] != '\0') 
  {
    char ch = expr[i];
    if (is_left(ch)) 
	{
      push(ch);
      i++;
    } 
	else if (is_right(ch)) 
	{
      if (is_pair(ch)) 
	  {
        pop();
        i++;
      } 
	  else
	  {
        return 0;
      }
    } 
	else 
	{
      i++;
    }
  }

  return is_empty();
}

int main() 
{
  printf("\nEnter your expression: ");
  char expression[MAX_SIZE];
  scanf("%s", expression);

  if (is_bracket_balanced(expression)) 
  {
    printf("\nBrackets are Balanced.\n");
  } 
  else 
  {
    printf("\nBrackets are not Balanced.\n");
  }

  return 0;
}


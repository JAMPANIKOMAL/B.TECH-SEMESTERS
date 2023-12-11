//Write a recursive program to print 1 to n where n will be provided by user.
//Method 1.
#include <stdio.h>
void print_number(int g, int i);
int main()
{
    int n;
    printf("Enter your number n: ");
    scanf("%d", &n);
    int i=1;
    print_number(n,i);
    return 0;
}

void print_number(int g,int i)
    {
        if(i==g+1)
        {
            return;
        }
        else
        {
            printf("%d", i);
            i++;
            print_number(g,i);
        }

    }
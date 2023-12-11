//Make a calculator using switch case.
#include <stdio.h>
int main()
{
    int n1,n2,i,n;
    while(n!=0)
    {
    printf("Enter 1 for Sum, 2 for Multplication, 3 for Divison, 4 for Subtraction and 0 to exit.\n");
    scanf("%d", &n);
    printf("Enter your first number: ");
    scanf("%d", &n1);
    printf("Enter your second number: ");
    scanf("%d", &n2);
    switch(n)
    {
    case 1:
    {
        printf("%d\n", n1+n2);
        break;
    }
    case 2:
    {
        printf("%d\n", n1*n2);
        break;
    }
    case 3:
    {
        printf("%d\n", n1/n2);
        break;
    }
    case 4:
    {
        printf("%d\n", n1-n2);
        break;
    }
    case 0:
    {
        goto A;
        break;

    }
    Default:
    {
        printf("Enter proper value of n.\n");
        break;
    }
    }
    }

    A:if (n==0)
    {
        printf("");
    }

    return 0;
}
    
    


//Write a C program to implement Doubly Linked List operations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int INFO;
    struct node * NEXT;
    struct node * PREVIOUS;
}; typedef struct node NODE;

NODE * FIRST = NULL;
NODE * LAST = NULL;

void insertab(int element);               //insertab --> Insert at begining
void insertae(int element);               //insertae --> Insert at the end
void insertasi(int element, int index);   //insertai --> Insert at the specific index
void deletetb();                          //deletetb --> Delete the begining node
void deletete();                          //deletete --> Delete the ending node
void deletetsi(int index);                //deletetsi --> Delete the node at a specific index
void display(void);                       //dispaly --> Print Doubly Linked List

int main()
{
    printf("\n");

    int choice;
    while(1)
    {
        printf("\nSelect an operation from the following to be performed on Doubly Linked List:");
        printf("\n1 --> Insert at the beginning.");
        printf("\n2 --> Insert at the end.");
        printf("\n3 --> Insert at a Specific Index.");
        printf("\n4 --> Delete the beginning node.");
        printf("\n5 --> Delete the ending node.");
        printf("\n6 --> Delete the node at a Specific Index.");
        printf("\n7 --> Print all the elements.");
        printf("\n8 --> To Exit");

        printf( "\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the element to be Inserted at the beginning of the Doubly Linked List: ");
                int tbinsertedab;
                scanf("%d", &tbinsertedab);
                insertab(tbinsertedab);
                break;
            }

            case 2:
            {
                printf("\nEnter the element to be Inserted at the end of the Doubly Linked List: ");
                int tbinsertedae;
                scanf("%d", &tbinsertedae);
                insertae(tbinsertedae);
                break;
            }

            case 3:
            {
                printf("\nEnter the element to be Inserted at the Specific Index of the Doubly Linked List: ");
                int tbinsertedae, index;
                scanf("%d", &tbinsertedae);
                printf("\nEnter the index after which the element to be inserted: ");
                scanf("%d", &index);
                insertasi(tbinsertedae, index);
                break;
            }

            case 4:
            {
                deletetb();
                break;
            }
            
            case 5:
            {
                deletete();
                break;
            }

            case 6:
            {
                int index;
                printf("\nEnter the index of the element to be deleted: ");
                scanf("%d", &index);
                deletetsi(index);
                break;
            }

            case 7:
            {
                display();
                break;
            }
            
            case 8:
            {
                printf("\n");
                exit(1);
                break;
            }
            
            default:
            {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }

    return 0;
}

void insertab(int element)
{
    NODE * PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = element;

    if (FIRST == NULL)
    {
        FIRST = LAST = PTR;
        PTR -> NEXT = NULL;
        PTR -> PREVIOUS = NULL;
        return;
    }
    else
    {
        FIRST -> PREVIOUS = PTR;
        PTR -> NEXT = FIRST;
        PTR -> PREVIOUS = NULL;
        FIRST = PTR;
        return;
    }
}

void insertae(int element)
{
    NODE *PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = element;

    if (FIRST == NULL)
    {
        FIRST = LAST = PTR;
        PTR -> NEXT = NULL;
        PTR -> PREVIOUS = NULL;
        return;
    }
    else
    {
        PTR -> PREVIOUS = LAST;
        LAST -> NEXT = PTR;
        PTR -> NEXT = NULL;
        LAST = PTR;
        return;
    }
}

void insertasi(int element, int index)
{
    NODE * TEMP = (NODE *)malloc(sizeof(NODE));
    NODE * PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = element;

    int count = 1;

    for(TEMP = FIRST; TEMP != LAST; TEMP = TEMP -> NEXT)
    {
        count = count + 1;
    }

    if(index > count)
    {
        printf("\nIndex out of range.\n");
    }
    
    else if (FIRST == NULL)
    {
        FIRST = LAST = PTR;
        PTR -> NEXT = NULL;
        PTR -> PREVIOUS = NULL;
        return;
    }
    else
    {
        int i = index;
        TEMP = FIRST;
        while (i>0)
        {
            TEMP = TEMP -> NEXT;
            i--;
        }
        PTR -> PREVIOUS = TEMP;
        PTR -> NEXT = TEMP -> NEXT;
        TEMP -> NEXT = PTR;
        return;
    }
}

void deletetb()
{
    NODE * TEMP = (NODE *)malloc(sizeof(NODE));

    if (FIRST == NULL)
    {
        printf("\nDoubly Linked List is empty.");
        return;
    }
    else
    {
        TEMP = FIRST -> NEXT;
        TEMP -> PREVIOUS = NULL;
        FIRST = TEMP;
        return;
    }
}

void deletete()
{
    NODE * TEMP = (NODE *)malloc(sizeof(NODE));

    if (FIRST == NULL)
    {
        printf("\nDoubly Linked List is empty.");
        return;
    }
    else
    {
        TEMP = LAST -> PREVIOUS;
        TEMP -> NEXT = NULL;
        LAST = TEMP;
        return;
    }
}

void deletetsi(int index)
{
    NODE * TEMP1 = (NODE *)malloc(sizeof(NODE));

    int count = 1;

    for(TEMP1 = FIRST; TEMP1 != LAST; TEMP1 = TEMP1 -> NEXT)
    {
        count = count + 1;
    }
    
    if (FIRST == NULL)
    {
        printf("\nDoubly Linked List is empty.");
        return;
    }
    else if(index > count)
    {
        printf("\nIndex out of range.\n");
    }
    else if(index == 0)
    {
        deletetb();
        return;
    }
    else if(index == count - 1)
    {
        deletete();
    }
    else 
    {
        int i = index;
        TEMP1 = FIRST;
        while (i>0)
        {
            TEMP1 = TEMP1 -> NEXT;
            i--;
        }
        TEMP1 -> PREVIOUS -> NEXT = TEMP1 -> NEXT;
        TEMP1 -> NEXT  -> PREVIOUS = TEMP1 -> PREVIOUS;
        return;
    }
}

void display()
{
    NODE *PTR;

    if (FIRST == NULL)
    {
        printf("\nDoubly Linked List is empty.\n");
        return;
    }
    else
    {
       printf("\nThe elements of Linked List are: \n");
       for(PTR = FIRST; PTR != NULL; PTR = PTR -> NEXT)
       {
            printf("%d ", PTR -> INFO);
       }
       printf("\n");
    }
}
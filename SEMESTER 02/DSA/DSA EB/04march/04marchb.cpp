//LINKED LIST
//LET US ASSUME THE LINKED LIST IS ASCENDING ORDER.

#include <iostream>
using namespace std;

struct node
{
    int INFO;
    struct node *NEXT;
};typedef struct node NODE;

NODE *FIRST = NULL;
NODE *LAST = NULL;

void insertab(int element);    //insertab --> Insert at begining
void insertae(int element);    //insertae --> Insert at the end
void inserteby(int element);    //inserteby --> Insert element entered by you
int remove(int element);
void display(void);
NODE * search(int element);

int main()
{
    cout << endl;
    int choice;
    while(1)
    {
        cout << "\nSelect an option from the following:";
        cout << "\n1 --> Insert at the beginning of the Linked List.";
        cout << "\n2 --> Insert at the end of the Linked List.";
        cout << "\n3 --> Insert specific element entered by you.";
        cout << "\n4 --> Delete specific element entered by you.";
        cout << "\n5 --> Search specific element entered by you.";
        cout << "\n6 --> Print all the linked list elements.";
        cout << "\n7 --> To Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "\nEnter the element to be Inserted at the beginning of the Linked List: ";
                int tbinsertedab;
                cin >> tbinsertedab;
                insertab(tbinsertedab);
                break;
            }
            case 2:
            {
                cout << "\nEnter the element to be Inserted at the end of the Linked List: ";
                int tbinsertedae;
                cin >> tbinsertedae;
                insertae(tbinsertedae);
                break;
            }
            case 3:
            {
                cout << "\nEnter the element to be Inserted in the Linked List: ";
                int tbinsertedeby;
                cin >> tbinsertedeby;
                inserteby(tbinsertedeby);
                break;
            }
            case 4:
            {
                cout << "\nEnter the element to be Deleted from the Linked List: ";
                int tbdeleted;
                cin >> tbdeleted;
                int don = remove(tbdeleted);   //don --> deleted or not.
                if(don == tbdeleted)
                {
                    cout << endl << tbdeleted << " is deleted from the Linked list." << endl; 
                }
                else
                {
                    cout << endl << tbdeleted << " is not present in the Linked list." << endl; 
                }
                break;
            }
            case 5:
            {
                cout << "\nEnter the element to be searched in the Linked List: ";
                int tbsearched;
                cin >> tbsearched;
                NODE *ion = search(tbsearched);   //ion --> inserted or not.
                if(ion == NULL)
                {
                    cout << endl << tbsearched << " is not present in Linked list." << endl;
                }
                else if(ion == FIRST)
                {
                    cout << endl << tbsearched << " is the First element in Linked list." << endl;
                }
                else if(ion == LAST)
                {
                    cout << endl << tbsearched << " is the Last element in Linked list." << endl;
                }
                else
                {
                    cout << endl << tbsearched << " is present before the element " << ion ->INFO << " in the Linked list." << endl;
                }
                break;
            }
            case 6:
            {
                display();
                break;
            }
            case 7:
            {
                cout << endl;
                exit(1);
                break;
            }
            default:
            {
                cout << "\nInvalid choice.";
                cout << endl;
                break;
            }
        }
    }

    return 0;
}

void insertab(int element)
{
    NODE *PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = element;

    if (FIRST == NULL)
    {
        FIRST = LAST = PTR;
        PTR -> NEXT = NULL;
        return;
    }
    else
    {
        PTR -> NEXT = FIRST;
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
        return;
    }
    else
    {
        LAST -> NEXT = PTR;
        PTR -> NEXT = NULL;
        LAST = PTR;
        return;
    }
}

void inserteby(int element)
{
    NODE *PTR = (NODE *)malloc(sizeof(NODE));
    PTR -> INFO = element;
    NODE *TEMP;

    if (FIRST == NULL)
    {
        FIRST = LAST = PTR;
        PTR -> NEXT = NULL;
        return;
    }
    else if(element <= FIRST -> INFO)
    {
        insertab(element);
        return;
    }
    else if(element >= LAST -> INFO)
    {
        insertae(element);
        return;
    }
    else
    {
        for(TEMP = FIRST; TEMP != LAST; TEMP = TEMP -> NEXT)
        {
            if(TEMP -> INFO < element)
            {
                if(element <= (TEMP -> NEXT) -> INFO)
                {
                    PTR -> NEXT = TEMP -> NEXT;
                    TEMP -> NEXT = PTR;
                }
            }
            // else
            // {
            //     PTR -> NEXT = TEMP;
            // }
        }
        return;
    }
}

int remove(int element)
{
    NODE *LOC, *TEMP;

    LOC = search(element);
    if (LOC == NULL)
    {
        return 0;
    }
    else if(LOC == FIRST)
    {
        if (FIRST == LAST)
        {
            FIRST = LAST = NULL;
            free(LOC);
            return(element);
        }
        else
        {
            FIRST = FIRST -> NEXT;
            free(LOC);
            return(element);
        }
    }
    else
    {
        for(TEMP = FIRST; TEMP -> NEXT != LOC; TEMP = TEMP -> NEXT);
        if(LOC == LAST)
        {
            TEMP -> NEXT = NULL;
            LAST = TEMP;
            free(LOC);
            return(element);
        }
        else
        {
            TEMP -> NEXT = LOC -> NEXT;
            free(LOC);
            return(element);
        }
    }
}

NODE * search(int element)
{
    NODE *PTR;

    if(FIRST == NULL)
    {
        return(NULL);
    }
    else if(FIRST -> INFO == element)
    {
        return(FIRST);
    }
    else
    {
        for(PTR = FIRST -> NEXT; PTR !=LAST; PTR = PTR -> NEXT)
        {
            if(PTR -> INFO == element)
            {
                return(PTR);
            }
        }
    }

    if(LAST -> INFO == element)
    {
        return(LAST);
    }
    else
    {
        return(NULL);
    }

}

void display()
{
    NODE *PTR;

    if (FIRST == NULL)
    {
        cout << "\nLinked List is empty.\n";
        cout << endl;
        return;
    }
    else
    {
       cout << "\nThe elements of Linked List are: \n";
       for(PTR = FIRST; PTR != NULL; PTR = PTR -> NEXT)
       {
            cout << PTR -> INFO <<" ";
       }
       cout << endl;
    }
}
//LINKED LIST
#include <iostream>
using namespace std;

struct node
{
    int INFO;
    struct node *NEXT;
};typedef struct node NODE;

NODE *FIRST = NULL;
NODE *LAST = NULL;

void insert(int element);
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
        cout << "\n1 --> Insert at end.";
        cout << "\n2 --> Delete specific element entered by you.";
        cout << "\n3 --> Search specific element entered by you.";
        cout << "\n4 --> Print all the linked list elements.";
        cout << "\n5 --> To Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "\nEnter the element to be Inserted into the Linked List at the end: ";
                int tbinserted;
                cin >> tbinserted;
                insert(tbinserted);
                break;
            }
            case 2:
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
            case 3:
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
            case 4:
            {
                display();
                break;
            }
            case 5:
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

void insert(int element)
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
            cout << PTR -> INFO;
       }
       cout << endl;
    }
}
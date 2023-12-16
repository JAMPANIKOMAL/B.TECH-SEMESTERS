//Implement a program to merge two sorted arrays into a single sorted array.
#include <stdio.h>
int main()
{
    //Arrays are user defined.
    int i=0, j=0, k=0, l=0;
    int sizea;
    printf("Enter the size of of your first 1d sorted array: ");
    scanf("%d", &sizea);
    int z=sizea;
    int a[sizea];
    printf("Enter the values of first 1d sorted array: \n");
    //Scanning values of first 1d sorted array from user.
    for (i=0; i<sizea; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &a[i]);
    }
    int sizeb;
    printf("Enter the size of of your second 1d sorted array: ");
    scanf("%d", &sizeb);
    int y=sizeb;
    int b[sizeb];
    printf("Enter the values of second 1d sorted array: \n");
    //Scanning values of second 1d sorted array from user.
    for (i=0; i<sizeb; i++)
    {
        printf("Enter the value of element %d: ", i);
        scanf("%d", &b[i]);
    }

    //Printing first 1d sorted array.
    printf("Your first 1d sorted array is: ");
    printf("{");
    for (i=0; i<sizea-1; i++)
    {
        printf("%d, ", a[i]);
    }
    for (i=sizea-1; i<sizea; i++)
    {
        printf("%d", a[i]);
    }
    printf("}\n");
    //Printing second 1d sorted array.
    printf("Your second 1d sorted array is: ");
    printf("{");
    for (i=0; i<sizeb-1; i++)
    {
        printf("%d, ", b[i]);
    }
    for (i=sizeb-1; i<sizeb; i++)
    {
        printf("%d", b[i]);
    }
    printf("}\n");
    
    int sizec = y+z;
    printf("%d", sizec);
    int c[sizec];

    while (i<sizea || j<sizeb || k<sizec)
    {
        if (a[i]<=b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else
        {
            c[k]=b[j];
            k++;
            j++;
        }
    }

    printf("Your merged 1d array is: ");
    printf("{");
    for (l=0; l<sizec-1; l++)
    {
        printf("%d, ", c[l]);
    }
    for (l=sizec-1; l<sizec; l++)
    {
        printf("%d", c[l]);
    }
    printf("}\n");

}
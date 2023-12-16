//Implement a program to merge two sorted arrays into a single sorted array.
#include <stdio.h>
int main()
{
    //Let us imagine two sorted arrays.
    int a[6]={1, 3, 5, 7, 9, 11};
    int b[6]={2, 4, 6, 8, 10, 12};
    int c[12];
    //printf("hi");
    int i=0, j=0, k=0;
    while (i<6 || j<6 || k<12)
    {
        if (a[i]<b[j])
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
    //printf("hi");

    printf("Your merged 1d array is: ");
    printf("{");
    for (int l=0; l<11; l++)
    {
        printf("%d, ", c[l]);
    }
    for (int l=11; l<12; l++)
    {
        printf("%d", c[l]);
    }
    printf("}\n");

}
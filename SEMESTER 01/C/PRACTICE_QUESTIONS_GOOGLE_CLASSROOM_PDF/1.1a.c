//Write a C program that will output this passage by Michael Singer. Make sure your output looks exactly as shown here (including spacing, line breaks punctuation, and the title and author). Use Required Escape Sequence and ASCII Value.
#include <stdio.h>

void print_trio1 (int a);

int main ()
{
    int a=12;
    printf("\n");
    print_trio1(a);
    printf("%c", 1);
    printf("\n");
    printf("%c \"If you are resisting something, you are feeding it.                  %c\n", 4, 4);
    printf("%c       Any energy you fight, you are feeding it.                       %c\n", 3, 3);
    printf("%c               If you are pushing something away,                      %c\n", 1, 1);
    printf("%c                       You are inviting it to stay.\"By Michael Singer. %c\n", 4, 4);
    print_trio1(a);
    printf("%c", 1);
    printf("\n");

    return 0;
}

void print_trio1 (int a)
{
    int i=0;
    while (i<a)
    {
        printf("%c %c %c ", 1, 4, 3);
        i++;
    }
}
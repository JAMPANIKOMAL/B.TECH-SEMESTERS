//Create programs to read from and write to files.
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *f1, *f2;
    char a;
    //Reading a file.
    if ((f1=fopen("hello.txt", "r") )==NULL)
    {
        printf("This file doesn't exist.\n");
    }
    else
    {
        while ((a=fgetc(f1))!=EOF)
        {
            printf("%c", a);
        }
    }
    fclose (f1);

    return 0;
}

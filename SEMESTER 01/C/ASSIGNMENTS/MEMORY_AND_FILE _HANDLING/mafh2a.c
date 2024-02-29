//Create programs to read from and write to files.
#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *f1, *f2;
    char a;
    //Writing to a file.
    if ((f1=fopen("hello.txt", "w"))==NULL)
    {
        printf("File does not exist.\n");
        exit(0);
    }

    else
    {
        printf ("Enter your text to be written to file and press enter and 'ctrl'+'c' to stop writing: \n" );
        while ((a=getchar())!=EOF)
        {
            fputc (a, f1);
        }
    }
    fclose(f1);


    return 0;
}

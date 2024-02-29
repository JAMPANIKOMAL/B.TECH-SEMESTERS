//Practice declaring and initializing variables of different data types.
#include <stdio.h>
int main()
{
    //Data type: Integer (int).
    //Initialization:
    int a;
    int b, c;

    //Declaration:
    a=4;
    c=b=3;
    int c1=4;
    int a1=a, b1=3, c2, d1;

    printf("a=%d, b=%d, c=%d, c1=%d, b1=%d\n", a, b, c, c1, b1);


    //Data type: Float (float).
    //Initialization:
    float f;
    float g, h;

    //Declaration:
    f=g=4.678;
    h=3.3;
    float i1=4;
    float f1=f, g1=3, h1, i;

    printf("f=%f, g=%f, h=%f, i1=%f, f1=%f\n", f, g, h, i1, f1);


    //Data type: Character (char).
    //Initialization:
    char l1;
    char m, m1;

    //Declaration:
    l1=m='j';
    char n2='k';
    char l=m, n=l, o=n2;

    printf("l1=%c, m=%c, n2=%c, n=%c, o=%c\n", l1, m, n2, n, o);



    //Data type: String (char* or char string_name[]).
    //Initialization:
    char *p;
    char q1[4];
    char *r1, s1, t1;
    char u1[5], v[9], x[1];

    //Declaration:
    p="JKC";
    char * q="Jampani Komal";
    char r, s[8]="Chowdary", t, u;

    printf("%s", p);

    
    //For int, float and char:
    a=b; //Assigning b to a.
    a==b; //Comparing a and b.


    return 0;
}
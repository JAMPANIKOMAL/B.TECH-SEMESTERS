//Write programs to demonstrate the usage of arithmetic, relational, logical, and bitwise operators.
#include <stdio.h>
int main()
{
    //Arithmetic operators: Two types Unary and Binary.
    //Unary:
    int a=3, b=4;
    printf("%d\n", -a); //Here '-' changes the sign of a.
    printf("%d\n", +b);

    //Binary:
    int c=3, d=9;
    printf("%d\n", c+d); // '+' adds c and d.
    printf("%d\n", c-d); // '-' subtractcs d from c.
    printf("%d\n", c*d); // '*' multiplies c and d.
    printf("%d\n", c/d); // '/' divides c by d.
    printf("%d\n", c%d); // '%' gives the reminder of c/d.
    

    //Relational operators: Used to compare two values.
    //They return '0' or 'False' if the condition is wrong and '1' or 'True' if the condition is correct.
    int e=9, f=13;
    printf("%d\n", e<f ); // '<'  less than.
    printf("%d\n", e<=f); // '<=' less than or equal to.
    printf("%d\n", e==f); // '==' equal to.
    printf("%d\n", e!=f); // '!=' not equal to.
    printf("%d\n", e>f ); // '>'  greater than.
    printf("%d\n", e>=f); // '>+' greater than or equal to.


    //Logical or Boolean Operators.
    //They return '0' or 'False' if the condition is wrong and '1' or 'True' if the condition is correct.
    int g=0, h=1; //0 means False and 1 means True.
    printf("%d\n", g&&h ); // '&&' AND.
    printf("%d\n", g||h);  // '||' OR.
    printf("%d\n", !g);    // '!'  NOT. It is a unary operator.


    //Bitwise opertors: They operate on bits.
    //int g=0, h=1; //0 means False and 1 means True.
    printf("%d\n", g&h ); // '&'  Bitwise AND. Binary, returns 1 if both are 1 and 0 if anyone is 0.
    printf("%d\n", g|h);  // '|'  Bitwise OR. Binary, returns 1 if anyone is 1 and 0 if both are 0. 
    printf("%d\n", g^h);  // '^'  Bitwise XOR. Binary, returns 1 if both are different and 0 if both are same.
    printf("%d\n", ~g);   // '~'  One's Complement. Unary, retuens 0 if 1 and 1 if 0.
    printf("%d\n", g<<2); // '<<' Bitwise Left Shift. Shifts bits to left by specified number.
    printf("%d\n", g>>2); // '>>' Bitwise Right Shift. Shifts bits to right by specified number.
    

    return 0;
}
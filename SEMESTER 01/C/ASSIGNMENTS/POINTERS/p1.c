//Write programs to demonstrate the usage of pointers (pointer arithmetic, passing pointers to functions).
#include <stdio.h>
void print_num (int *a, int *b, int *c);

int main ()
{
    int a=1, b=2, c=3;
    int *ap=&a, *bp=&b, *cp=&c;  //Adress of a is stored in ap, b in bp and c in cp.
    printf("\na=%d, b=%d, c=%d\n", a, b, c); //Printing values.
    printf("Address of a=%d, Address of b=%d, Address of c=%d\n", &a, &b, &c); //Printing address.
    printf("Address of a=%d, Address of b=%d, Address of c=%d\n", ap, bp, cp); //Printing address using pointers.

    //printf("%d", sizeof(int));
    ap=ap+1; //Adding 4 (size of int since pointer is of type int) to address.
    printf("Incrementing pointer ap by 1: %d\n", ap);
    ap=ap-1; //Subtracting 4 (size of int since pointer is of type int) to address.
    printf("Decrementing pointer ap by 1: %d\n", ap);
    print_num(ap, bp, cp);
    
    
    return 0;
}
    
void print_num (int *a, int *b, int *c)
{
    c++;
    printf("%d\n", c);  //Incrementing pointer b and storing it in c.
}  

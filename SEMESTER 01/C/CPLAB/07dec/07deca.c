//Write a C programm to print pointer, variable, variable address, and others etc.
//CE
#include <stdio.h>
int main()
{
    int a;
    a=13;
    int *a1, **a2;  //Pointer.
    a1=&a;   
    a2=&a1;
    printf("%d\n", a);    //Prints variable's value.
    printf("%d\n", a1);   //Prints variable's address in decimal.
    printf("%d\n", &a);   //Prints variable's address in decimal.
    printf("%p\n", &a);   //Prints variable's address in hexadecimal.
    printf("%p\n", a1);   //Prints variable's address in hexadecimal.
    printf("%d\n", *a1);  //Prints variable's value.
    printf("%d\n", &a1);  //Prints variables's pointer's address in decimal.
    printf("%p\n", &a1);  //Prints variables's pointer's address in hexadecimal.
    printf("%d\n", a2);   //Prints variables's pointer's address in decimal.
    printf("%p\n", a2);   //Prints variables's pointer's address in hexadecimal.
    printf("%d\n", &a2);  //Prints variables's pointer's pointer's address in decimal.
    printf("%p\n", &a2);  //Prints variables's pointer's pointer's address in hexadecimal.
    printf("%d\n", *a2);  //Prints variable's address in decimal.
    printf("%p\n", *a2);  //Prints variable's address in hexadecimal.
    printf("%d\n", **a2); //Prints variable's value.
    printf("%d\n", &*a2); //Prints variable's pointer's address in decimal.
    printf("%p\n", &*a2); //Prints variable's pointer's address in hexadecimal.
    printf("%d\n", &**a2);//Prints variable's address in decimal.
    printf("%p\n", &**a2);//Prints variable's  address in hexadecimal.
    

    return 0;
}

//Experiment with typecasting in C.
#include <stdio.h>
int main()
{
    //There are two types of type conversions. First one is Implicit i.e., done by computer and the other is Explicit which is done by user.
    //Implicit type of conversion.
    char c1, c2;
    int i1, i2;
    float f1, f2;
    c1='J';
    i1=33.56; //*Demotion: float converted to int, only 33 is assigned to i1.
    f1=13.6;
    c2=i1; //Demotion: int converted to char.
    i2=f1; //Demotion: float converted to int.
    //Now c2 has character with ASCII value 33, i2 is assigned value 13.
    printf("c2=%c, i2=%d\n", c2, i2);
    f2=i1; //Promotion: int converted to float.
    i2=c1; //Promotion: char converted to int. 
    //Now i2 contains ASCII value of character 'J' which is 74.
    printf("f2=%f, i2=%d\n", f2, i2);

    //Explict type of conversion.
    int x=5, y=2;
    float p, q;
    p=x/y;
    printf("p = %f\n", p);
    q=(float)x/y;
    printf("q = %f\n", q);
    
    
    return 0;
}
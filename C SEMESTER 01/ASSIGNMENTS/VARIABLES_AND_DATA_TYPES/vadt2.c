//Implement programs to perform arithmetic operations (addition, subtraction, multiplication, division) on variables.
#include <stdio.h>
int main()
{
    //Data type: Integer (int).
    //Initialization:
    int a, b, c=3, d, e=7;
    //Arithmetic operations:
    a=c+e; //Sum.
    b=e-c; //Difference.
    d=b/a; //Division.
    a=b*c*d*e; //Product.
    printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);

    //Data type: Float (float).
    //Initialization:
    float a1, b1, c1=3.9, d1, e1=7.7;
    //Arithmetic operations:
    a1=c1+e1; //Sum.
    b1=e1-c1; //Difference.
    d1=b1/a1; //Division.
    a1=b1*c1*d1*e1; //Product.
    printf("a1=%f, b1=%f, c1=%f, d1=%f, e1=%f\n", a1, b1, c1, d1, e1);


    //For int, float and char:
    a=b; //Assigning b to a.
    a==b; //Comparing a and b.


    return 0;
}
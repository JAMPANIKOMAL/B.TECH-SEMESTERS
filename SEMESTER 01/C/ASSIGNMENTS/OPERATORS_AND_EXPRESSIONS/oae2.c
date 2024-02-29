//Write a program to calculate the area of a triangle using Heron's formula.
//Herons formula: square root of ((s)(s-a)(s-b)(s-c)) where s is (a+b+c)/2.
#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, s;
    printf("Enter the value of first side of triangle: ");
    scanf("%f", &a);
    printf("Enter the value of second side of triangle: ");
    scanf("%f", &b);
    printf("Enter the value of third side of triangle: ");
    scanf("%f", &c);
    s=((a+b+c)/2);
    printf("Area of the triangle is %f.\n", (sqrt((s)*(s-a)*(s-b)*(s-c))));
   
    return 0;
}
//Implement a program that calculates the area of a rectangle and a circle based on user input.
#include <stdio.h>
int main()
{
    int length, breadth;
    float radius;
    printf("Enter the length of rectangle: ");
    scanf("%d", &length);
    printf("Enter the breadth of rectangle: ");
    scanf("%d", &breadth);
    printf("Area of the rectangle is: %d.\n", length*breadth);
    printf("Enter the radius of circle: ");
    scanf("%f", &radius);
    printf("Area of the circle is: %f.\n", radius*radius*3.14);

    return 0;
}
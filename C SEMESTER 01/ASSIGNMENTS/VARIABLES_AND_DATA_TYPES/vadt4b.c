//Write a program that converts temperature from Celsius to Fahrenheit and vice versa.
#include <stdio.h>
int main()
{
    //Program that converts temperature from Fahrenheit to Celsius.
    float celsius, fahrenheit;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    printf("Temperature in Celsius is %f\n", ((fahrenheit-32)*5/9));
    
    
    return 0;
}
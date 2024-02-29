//Write a program that converts temperature from Celsius to Fahrenheit and vice versa.
#include <stdio.h>
int main()
{
    //Program that converts temperature from Celsius to Fahrenheit.
    float celsius, fahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("Temperature in Fahrenheit is %f\n", ((celsius*9/5)+32));
    
    return 0;
}
//Create a program that stores employee information (name, ID, salary) and displays it using structures.
#include <stdio.h>
#include <string.h>
struct ofinfo 
{
    char name[30];
    int ID;
    int salary;
}e1, e2;

int main()
{
    struct ofinfo e1={"Tejas Prakash Patil", 001, 30000};
    e2.ID = 002;
    strcpy(e2.name, "Aashutosh Thakur");
    e2.salary = 40000;
    printf("\nEmplyee 01:- Name: %s, ID: %d, Salary: %d.\n", e1.name, e1.ID, e1.salary);
    printf("Emplyee 02:- Name: %s, ID: %d, Salary: %d.\n", e2.name, e2.ID, e2.salary);

    return 0;
}
//Write a c programm to display employee details (employee id, name and department using structures.)
//Question: Perfrom arithmetic operations in structures.
//





//
#include <stdio.h>
struct ofinfo 
{
    int id;
    char * name;
    char * department;
};

int main()
{
    struct ofinfo e1={01, "Tejas Prakash Patil", "R&D"};
    struct ofinfo e2;
    e2.id = 02;
    e2.name = "Aashutosh Thakur";
    e2.department = "Accounts";
    printf("Emplyee 01:- id: %d, Name: %s, Department: %s.\n", e1.id, e1.name, e1.department);
    printf("Emplyee 02:- id: %d, Name: %s, Department: %s.\n", e2.id, e2.name, e2.department);
    return 0;


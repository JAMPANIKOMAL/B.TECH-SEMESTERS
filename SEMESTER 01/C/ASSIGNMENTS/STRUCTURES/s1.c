//Develop a program to calculate the total marks and average marks of students using structures.
#include <stdio.h>
struct student 
{
    char name[30];
    int marks;
}s1, s2, s3;
int main ()
{
    printf("Enter the name of first student: ");
    scanf("%s", s1.name);
    printf("Enter the marks of %s: ", s1.name);
    scanf("%d", &s1.marks);
    printf("Enter the name of second student: ");
    scanf("%s", s2.name);
    printf("Enter the marks of %s: ", s2.name);
    scanf("%d", &s2.marks);
    printf("Enter the name of third student: ");
    scanf("%s", s3.name);
    printf("Enter the marks of %s: ", s3.name);
    scanf("%d", &s3.marks);
    printf("Total marks of all the students are %d.\n", s1.marks+s2.marks+s3.marks);
    printf("Average marks of all the students are %f.\n", ((s1.marks+s2.marks+s3.marks)/(float)3));
    
    return 0;
}
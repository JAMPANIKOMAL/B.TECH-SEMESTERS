//Write a c programm to find a approximate age of a student when student name, date of birth and current date will be provided by user using structure.
#include <stdio.h>
struct agecalc 
{
    char * name;
    char * dob;
};

int main()
{
    struct agecalc stu1;
    printf("Enter your name: ");
    scanf("%s", stu1.name);
    printf("Enter your Date of Birth in DD-MM-YYYY format including hyphens: ");
    scanf("%s", stu1.dob);
    char * cdate;
    printf("Enter current date in DD-MM-YYYY format including hyphens:");
    scanf("%s", cdate);
    int d, m, y;
    d=(stu1.dob[0]+stu1.dob[1]);
    m=(stu1.dob[3]+stu1.dob[4]); 
    y=(stu1.dob[6]+stu1.dob[7]+stu1.dob[8]+stu1.dob[9]);
    int cd, cm, cy;
    cd=(cdate[0]+cdate[1]);
    cm=(cdate[3]+cdate[4]); 
    cy=(cdate[6]+cdate[7]+cdate[8]+cdate[9]);

    if (m>cm)
    {
        printf("Your age is %d.\n", cy-y-1);
    }
    else
    {
        printf("Your age is %d.\n", cy-y);
    }


    return 0;
}
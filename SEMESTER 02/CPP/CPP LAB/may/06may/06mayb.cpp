//OVERLOADING + OPERATOR & / OPERATOR SUCH THAT PROGRAM FINDS AVERAGE MARKS OF STUDENTS.
//WORKING BUT FIND ANOTHER METHOD.
//STUDENT NAME NOT INCLUDED.

#include <iostream>
using namespace std;

class Student
{
    private:
        string name;
        float maths_marks;
        float physics_marks;
        float chemistry_marks;
        float total_marks;
    
    public:
        Student()
        {
            maths_marks = 0;
            physics_marks = 0;
            chemistry_marks = 0;
            total_marks = 0;
        }
        
        Student(float m, float p, float c)
        {
            maths_marks = m;
            physics_marks = p;
            chemistry_marks = c;
            total_marks = m + p + c;
        }

        void display()
        {
            cout << "Maths Marks: " << maths_marks << endl;
            cout << "Physics Marks: " << physics_marks << endl;
            cout << "Chemistry Marks: " << chemistry_marks << endl;
            cout << "Total Marks: " << total_marks << endl;
        }

        Student operator + (Student);
        Student operator / (Student);
};

Student Student :: operator + (Student S)
{
    Student temp;

    temp.maths_marks = maths_marks + S.maths_marks;
    temp.physics_marks = physics_marks + S.physics_marks;
    temp.chemistry_marks = chemistry_marks + S.chemistry_marks;
    temp.total_marks = total_marks + S.total_marks;

    return temp;
}

Student Student ::  operator / (Student S)
{
    Student temp;

    temp.maths_marks = maths_marks / S.maths_marks;
    temp.physics_marks = physics_marks / S.physics_marks;
    temp.chemistry_marks = chemistry_marks / S.chemistry_marks;
    temp.total_marks = (total_marks / S.total_marks) * 3;   //NOT GETTING CORRECT. OUTPUT GETTING CORRECT OUTPUT AFTER USING FLOAT.

    //temp.total_marks = total_marks / S.maths_marks;


    return temp;
}

int main()
{
    cout << endl;
    
    Student S1(97, 92, 89);
    Student S2(93, 87, 72);
    Student S3(2, 2, 2);
    Student S4;

    S1.display();
    cout << endl;
    S2.display();
    cout << endl;

    S4 = S1 + S2;
    S4 = S4 / S3;

    cout << "Average Marks: " << endl; 
    S4.display();

    cout << endl;

    return 0;
}
//HAPPENED IN CLASS NOT IN LAB COMBINED.

#include <iostream>
using namespace std;

class Student
{
    private:
        string name;
        int maths_marks;
        int physics_marks;
        int chemistry_marks;
    
    public:
        int total_marks;

        Student()
        {
            maths_marks = 0;
            physics_marks = 0;
            chemistry_marks = 0;
            total_marks = 0;
        }
        
        Student(int m, int p, int c)
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

int main()
{
    cout << endl;

    float class_average = 0;
    
    Student S1(97, 92, 89);
    Student S2(93, 87, 72);
    Student S3;

    S1.display();
    cout << endl;
    S2.display();
    cout << endl;

    S3 = S1 + S2;

    cout << "S3: " << endl;
    S3.display();
    cout << endl;

    class_average = S3.total_marks / 2;

    cout << "Total Average Marks: " << class_average << endl; 

    cout << endl;

    return 0;
}
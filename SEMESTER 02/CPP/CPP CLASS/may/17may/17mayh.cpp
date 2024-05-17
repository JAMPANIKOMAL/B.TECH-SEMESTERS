//this pointer

#include <iostream>
using namespace std;

class person
{
    private:
        int age;

    public:
        person(int x) 
        {
            age = x;
        }

        void dispaly()
        {
            cout << "Age = " << age << endl;
        }

        person oldperson(person p)
        {
            if (age > p.age)
            {
                return *this;
            }

            else
            {
                return p;
            }
        }
};

int main()
{
    cout << endl;

    person r(35), h(30);
    person  o = r.oldperson(h);
    o.dispaly();

    cout << endl;

    return 0;
}
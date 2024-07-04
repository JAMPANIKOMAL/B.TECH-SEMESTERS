#include <iostream>
using namespace std;

class person
{
    protected:
        string name;
        int age;
        string address;

    public:
        virtual void getdetails() = 0;
};

class student: public person
{
    protected:
        int semester;
        double percentage;
    
    public:
        void getdetails()
        {
            cin >> name;
            cin >> age;
            cin >> address;
            cin >> semester;
            cin >> percentage;
        }
};

class patient: public person
{
    protected:
        string bloodgroup;
        double height;
        double weight;
    
    public:
        void getdetails()
        {
            cin >> name;
            cin >> age;
            cin >> address;
            cin >> bloodgroup;
            cin >> height;
            cin >> weight;
        }
};

int main()
{



    return 0;
}
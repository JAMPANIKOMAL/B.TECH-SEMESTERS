//Find the mean of given two values using Friend Function,

#include<iostream>
using namespace std;

class Mean
{
    private:
        float m1, m2;
        friend void printMean(Mean M1);
    public:
        void setdata(float a, float b)
        {
            m1 = a;
            m2 = b;
        }
};

void printMean(Mean M1)
{
    float mean = (M1.m1 + M1.m2)/2;
    cout << "Mean = " << mean;
}

int main()
{
    cout << endl;
    Mean M1;
    M1.setdata(3, 4);
    printMean(M1);
    cout << endl << endl;

    return 0;
}
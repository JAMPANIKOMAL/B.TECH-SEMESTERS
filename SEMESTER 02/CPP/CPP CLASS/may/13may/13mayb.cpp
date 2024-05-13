//Virtual Base Class
//COMPLETE THIS CODE.
#include <iostream>
using namespace std;

class A
{
    public:
        int i;
};

class B : virtual public A
{
    public:
        int j;
};

class C : public virtual A
{
    public:
        int k;
};

class D : public B, public C
{
    public:
        int K;
};


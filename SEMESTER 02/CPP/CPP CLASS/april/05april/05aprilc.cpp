//You are working in a data processing center, demonstrate a constructor where the input string will be taken by user nad print number of vowels in it.

#include<iostream>
using namespace std;

class String
{
    private:
        string s1;
        int nov;
    public:
        String()
        {
            cout << "Enter Your String: ";
            cin >> s1;
            int count = 0;
            for(int i = 0; i < s1.length(); i++)
            {
                if(s1[i] == 'a' or s1[i] == 'e' or s1[i] == 'i' or s1[i] == 'o' or s1[i] == 'u')
                {
                    count = count + 1;
                }
            }
            nov = count;
        }
        void display()
        {
            cout << "Number of vowels in the string \"" << s1 << "\" are " << nov << ".";
        }
};

int main()
{
    cout << endl;
    String S1;
    S1.display();
    cout << endl << endl;

    return 0;
}
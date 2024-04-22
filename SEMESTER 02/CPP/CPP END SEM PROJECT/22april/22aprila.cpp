#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class sira
{
    protected:
        string name;
        long long mobile_number;

    public:
        void signin();
        void signup();
};

class patient : public sira
{
    protected:
        string username, password;
        string address;
        vector <string> usernames;
        vector <string> passwords;

    public:
        patient()
        {
            ifstream myfile1; 
            myfile1.open("patientusernames.txt");
            string mystring1;

            if (myfile1.is_open()) 
            {
                myfile1 >> mystring1; 
                while(mystring1 != "end")
                {
                    usernames.push_back(mystring1);
                    myfile1 >> mystring1;
                }
            }

            ifstream myfile2; 
            myfile2.open("patientpasswords.txt");
            string mystring2;

            if (myfile2.is_open()) 
            {
                myfile2 >> mystring2; 
                while(mystring2 != "end")
                {
                    usernames.push_back(mystring2);
                    myfile2 >> mystring2;
                }
            }
        }

        void sigin()
        {
            string u1, p1;
            cout << "Username: ";
            cin >> u1;
            cout << "Password: ";
            cin >> p1;

            bool flag = false;
            for(int i = 0; i < usernames.size(); i++)
            {
                if(u1 == usernames[i] && p1 == passwords[i])
                {
                    flag = true;
                    exit;
                }
            }
            
            if(flag == true)
            {
                cout << "Login Succesful!";
            }
            else
            {
                cout << "Wrong Credentials!";
            }
        }
        
};

int main()
{
    patient p1;
    p1.sigin();
}


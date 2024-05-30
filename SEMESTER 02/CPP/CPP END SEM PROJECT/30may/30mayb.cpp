//UPDATED ADMIN CODE.

#include <iostream>
#include <vector>
using namespace std;

class admin
{
    protected:
        string admin_hospitalname;
        string admin_username;
        string admin_password;
        long long admin_phone1;
        long long admin_phone2;  //phone2 or emergnecy home contact number
        string admin_mail;
        string admin_address;
        string admin_hospitalid;
        long long admin_uniquecode;
        
        vector <string> admin_names {"Apollo"};
        vector <string> admin_usernames {"apollo"};
        vector <string> admin_passwords {"apollo1"};
        vector <long long> admin_phone1s {9924492472};
        vector <long long> admin_phone2s {0}; //0 represnts phone number not provided.
        vector <string> admin_mails {"apollo.lavad@gmail.com"};
        vector <string> admin_addresses {"Near Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305"};
        vector <string> admin_hospitalids {"2343er", "4534ty"};
        vector <long long> admin_uniquecodes {33069, 33088};
        
    public:
        int admin_index;
        
        void admin_start()
        {
            admin_homemenu();
        }

        void admin_homemenu()
        {
            while(1)
            {
                int a;
                cout << endl << "Hello!";
                cout << endl << "1. Login";
                cout << endl << "2. Signup";
                cout << endl << "3. Exit" << endl;
                cout << "> ";
                cin >> a;

                if(a == 1)
                {
                    admin_login();
                }
                else if(a == 2)
                {
                    admin_signup();
                }
                else if(a == 3)
                {
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choic!";
                }
            }
            
        }

        void admin_login()
        {
            cout << endl <<  "Enter Username: ";
            cin >> admin_username;
            cout << "Enter Password: ";
            cin >> admin_password;
            int flag = 0;

            for(int i = 0; i < admin_usernames.size(); i++)
            {
                if(admin_username == admin_usernames[i] && admin_password == admin_passwords[i])
                {
                    cout << endl << "Login Successfull!" <<endl;
                    admin_index = i;
                    flag = 1;
                    admin_menu();
                }
            }

            if(flag == 0) 
            {
                cout << "Invalid Credentials!" << endl;
                admin_homemenu();
            }
        }

        void admin_signup()
        {
            cout << endl << "Enter your Hospital Name: ";
            cin.ignore();
            getline(cin, admin_hospitalname);
            cout << "Enter your phone number: ";
            cin >> admin_phone1;
            cout << "Enter your alternate phone number: ";
            cin >> admin_phone2;
            cout << "Enter your mail Id: ";
            cin >> admin_mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, admin_address);
            cout << "Enter Hospital ID: ";
            cin >> admin_hospitalid;
            cout << "Enter a Username: ";
            cin >> admin_username;
            cout << "Enter password: ";
            cin >> admin_password;

            // admin_names.push_back(admin_hospitalname);
            // admin_phone1s.push_back(admin_phone1);
            // admin_phone2s.push_back(admin_phone2);
            // admin_mails.push_back(admin_mail);
            // admin_addresses.push_back(admin_address);
            // admin_hospitalids.push_back(admin_hospitalid);
            // admin_usernames.push_back(admin_username);
            // admin_passwords.push_back(admin_password);
            // admin_uniquecodes.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "We will contact you soon to verify your hospital!" << endl;
            admin_index = (admin_usernames.size() - 1);
            
            admin_homemenu();
        }

        void admin_viewprofile()
        {
            cout << endl << "Name: " << admin_names[admin_index];
            cout << endl << "Phone Number: " << admin_phone1s[admin_index];
            cout << endl << "Alternate Phone Number: " << admin_phone2s[admin_index];
            cout << endl << "Mail: " << admin_mails[admin_index];
            cout << endl << "Address: " << admin_addresses[admin_index];
            cout << endl << "NMC ID: " << admin_hospitalids[admin_index];
            cout << endl << "Username: " << admin_usernames[admin_index] << endl;
        }

        void admin_menu()
        {
            while(1)
            {
                int a;
                cout << endl << "1. View your Profile";
                cout << endl << "2. View your Patient's Profiles.";
                cout << endl << "3. View your Doctor's Profiles.";
                cout << endl << "4. View stock.";
                cout << endl << "5. Exit" << endl;
                cout << "> ";
                cin >> a;

                if(a == 1)
                {
                    admin_viewprofile();
                }
                else if(a == 2)
                {
                    admin_viewpatientsprofile();
                }
                else if(a == 3)
                {
                    admin_viewdoctorsprofile();
                }
                
                else if(a == 4)
                {
                    admin_viewstock();
                }
                else if(a == 5)
                {
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!";
                }
            }

        }

        void admin_viewpatientsprofile()
        {
            cout << " Code Under Progress!" << endl;
        }

        void admin_viewdoctorsprofile()
        {
            cout << " Code Under Progress!" << endl;
        }

        void admin_viewstock()
        {
            cout << " Code Under Progress!" << endl;
        }
};

int main()
{
    int choice;
    while (1)
    {
        int a;
        cout << endl
             << "Who are you?";
        cout << endl
             << "1. Pateint";
        cout << endl
             << "2. Doctor";
        cout << endl
             << "3. Admin";
        cout << endl
             << "4. Exit" << endl;
        cout << "> ";
        cin >> a;
        if (a == 1)
        {
            //patient p1;
            //p1.patient_start();
        }
        else if (a == 2)
        {
            // doctor d1;
            // d1.doctor_homemenu();
        }
        else if (a == 3)
        {
            admin a1;
            a1.admin_homemenu();
        }
        else if (a == 4)
        {
            exit(1);
        }
        else
        {
            cout << "Invalid Choice;";
        }
    }
}

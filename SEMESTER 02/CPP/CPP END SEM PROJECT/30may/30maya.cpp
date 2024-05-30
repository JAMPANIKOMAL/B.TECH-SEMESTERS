//UPDATED DOCTOR CODE

#include <iostream>
#include <vector>
using namespace std;

class doctor
{
    protected:
        string doctor_name;
        string doctor_username;
        string doctor_password;
        long long doctor_phone1;
        long long doctor_phone2;  //phone2 or emergnecy home contact number
        string doctor_mail;
        string doctor_address;
        string doctor_citizenid;
        string doctor_nmcid;
        string doctor_bloodgroup;
        long long doctor_uniquecode;
        
        vector <string> doctor_names {"Prasann Barot", "Rabel Guharoy"};
        vector <string> doctor_usernames {"prasann", "rabel"};
        vector <string> doctor_passwords {"prasann1", "rabel1"};
        vector <long long> doctor_phone1s {9924492472, 7980262223};
        vector <long long> doctor_phone2s {0, 0}; //0 represnts phone number not provided.
        vector <string> doctor_mails {"prasann.barot@rru.ac.in", "rabel.guharoy@rru.ac.in"};
        vector <string> doctor_addresses {"Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305", "Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305"};
        vector <string> doctor_bloodgroups {"B+", "O+"};
        vector <string> doctor_citizenids {"678677863561", "897765453442"};
        vector <string> doctor_nmcids {"2343er", "4534ty"};
        vector <long long> doctor_uniquecodes {33069, 33088};
        
    public:
        int doctor_index;
        
        void doctor_start()
        {
            doctor_homemenu();
        }

        void doctor_homemenu()
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
                    doctor_login();
                }
                else if(a == 2)
                {
                    doctor_signup();
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

        void doctor_login()
        {
            cout << endl <<  "Enter Username: ";
            cin >> doctor_username;
            cout << "Enter Password: ";
            cin >> doctor_password;
            int flag = 0;

            for(int i = 0; i < doctor_usernames.size(); i++)
            {
                if(doctor_username == doctor_usernames[i] && doctor_password == doctor_passwords[i])
                {
                    cout << endl << "Login Successfull!" <<endl;
                    doctor_index = i;
                    flag = 1;
                    doctor_menu();
                }
            }

            if(flag == 0) 
            {
                cout << "Invalid Credentials!" << endl;
                doctor_homemenu();
            }
        }

        void doctor_signup()
        {
            cout << endl << "Enter your Name: ";
            cin.ignore();
            getline(cin, doctor_name);
            cout << "Enter your phone number: ";
            cin >> doctor_phone1;
            cout << "Enter your alternate phone number: ";
            cin >> doctor_phone2;
            cout << "Enter your mail Id: ";
            cin >> doctor_mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, doctor_address);
            cout << "Enter blood group: ";
            cin >> doctor_bloodgroup;
            cout << "Enter citizenship ID: ";
            cin >> doctor_citizenid;
            cout << "Enter NMC ID: ";
            cin >> doctor_nmcid;
            cout << "Enter a Username: ";
            cin >> doctor_username;
            cout << "Enter password: ";
            cin >> doctor_password;

            doctor_names.push_back(doctor_name);
            doctor_phone1s.push_back(doctor_phone1);
            doctor_phone2s.push_back(doctor_phone2);
            doctor_mails.push_back(doctor_mail);
            doctor_addresses.push_back(doctor_address);
            doctor_bloodgroups.push_back(doctor_bloodgroup);
            doctor_citizenids.push_back(doctor_citizenid);
            doctor_nmcids.push_back(doctor_nmcid);
            doctor_usernames.push_back(doctor_username);
            doctor_passwords.push_back(doctor_password);
            doctor_uniquecodes.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "Visit your hospital to complete KYC to acces all features of the app!" << endl;
            doctor_index = (doctor_usernames.size() - 1);

            doctor_homemenu();
        }

        void doctor_viewprofile()
        {
            cout << endl << "Name: " << doctor_names[doctor_index];
            cout << endl << "Phone Number: " << doctor_phone1s[doctor_index];
            cout << endl << "Alternate Phone Number: " << doctor_phone2s[doctor_index];
            cout << endl << "Mail: " << doctor_mails[doctor_index];
            cout << endl << "Address: " << doctor_addresses[doctor_index];
            cout << endl << "Blood Group: " << doctor_bloodgroups[doctor_index];
            cout << endl << "Citizen ID: " << doctor_citizenids[doctor_index];
            cout << endl << "NMC ID: " << doctor_nmcids[doctor_index];
            cout << endl << "Username: " << doctor_usernames[doctor_index] << endl;
        }

        void doctor_menu()
        {
            while(1)
            {
                int a;
                cout << endl << "1. View your Profile";
                cout << endl << "2. View your Patient's Profiles.";
                cout << endl << "3. View your Appointments..";
                cout << endl << "4. Exit" << endl;
                cout << "> ";
                cin >> a;

                if(a == 1)
                {
                    doctor_viewprofile();
                }
                else if(a == 2)
                {
                    doctor_viewpatientsprofile();
                }
                else if(a == 3)
                {
                    doctor_viewappointments();
                }
                
                else if(a == 4)
                {
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!";
                }
            }

        }

        void doctor_viewpatientsprofile()
        {
            cout << "Code Under Progress!" << endl;
        }

        void doctor_viewappointments()
        {
            cout << "Code Under Progress!" << endl;
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
            doctor d1;
            d1.doctor_homemenu();
        }
        else if (a == 3)
        {
            //admin a1;
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

#include <iostream>
#include <vector>
using namespace std;

class sira
{
    protected:
        string name;
        string username;
        string password;
        long long phone1;
        long long phone2;  //phone2 or emergnecy home contact number
        string mail;
        string address;
        
public:
    virtual void login() = 0;
    virtual void signup() = 0;
    virtual void viewprofile() = 0;
    virtual void homemenu() = 0;
};

class patient : public sira
{
    protected:
    
        string citizenid;
        string bloodgroup;
        long long uniquecode;
        
        vector <string> patient_names {"Tejas Prakash Patil", "Aashutosh Thakur", "Jampani Komal"};
        vector <string> patient_usernames {"tejas", "aashutosh", "komal"};
        vector <string> patient_password {"tejas1", "aashutosh1", "komal1"};
        vector <long long> patient_phone1{7720841778, 8102568219, 9182048179};
        vector <long long> patient_phone2{0, 9825818717, 9704427177}; //0 represnts phone number not provided.
        vector <string> patient_mail {"tppatil397@gmail.com", "thakuraashutosh13@gmail.com", "jampanikomal2005@gmail.com"};
        vector <string> patient_address {"Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421", "Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421", "Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421"};
        vector <string> patient_bloodgroups {"B+", "O+", "B+"};
        vector <string> patient_citizenid{"230031101611052", "230031101611057", "230031101611054"};
        vector <long long> patient_uniquecode {23052, 23057, 23054};
        
    public:
        int index;
        
        patient()
        {
            homemenu();
                
        }

        void homemenu()
        {
            while(1)
            {
                int a;
                cout << endl << "Hello!";
                cout << endl << "1. Login";
                cout << endl << "2. Signup";
                cout << endl << "3. Exit" << endl;
                cout << ">";
                cin >> a;

                if(a == 1)
                {
                    login();
                }
                else if(a == 2)
                {
                    signup();
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

        void login()
        {
            cout << endl <<  "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            for(int i = 0; i < patient_usernames.size(); i++)
            {
                if(username == patient_usernames[i] && password == patient_password[i])
                {
                    cout << endl << "Login Successfull!" <<endl;
                    index = i;
                    menu();
                }
                else
                {
                    cout << "Invalid Credentials!" << endl;
                }
            }
        }

        void signup()
        {
            cout << endl << "Enter your Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter your phone number: ";
            cin >> phone1;
            cout << "Enter your alternate [Emergency] phone number: ";
            cin >> phone2;
            cout << "Enter your mail Id: ";
            cin >> mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter blood group: ";
            cin >> bloodgroup;
            cout << "Enter citizenship ID: ";
            cin >> citizenid;
            cout << "Enter a Username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            patient_names.push_back(name);
            patient_phone1.push_back(phone1);
            patient_phone2.push_back(phone2);
            patient_mail.push_back(mail);
            patient_address.push_back(address);
            patient_bloodgroups.push_back(bloodgroup);
            patient_citizenid.push_back(citizenid);
            patient_usernames.push_back(username);
            patient_password.push_back(password);
            patient_uniquecode.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "Visit nearest hospital to complete KYC to acces all features of the app!" << endl;
            index = (patient_usernames.size() - 1);
            homemenu();
        }

        void viewprofile()
        {
            cout << endl << "Name: " << patient_names[index];
            cout << endl << "Phone Number: " << patient_phone1[index];
            cout << endl << "Alternate Phone Number: " << patient_phone2[index];
            cout << endl << "Mail: " << patient_mail[index];
            cout << endl << "Address: " << patient_address[index];
            cout << endl << "Blood Group: " << patient_bloodgroups[index];
            cout << endl << "Citizen ID: " << patient_citizenid[index];
            cout << endl << "Unique Code: " << patient_uniquecode[index];
            cout << endl << "Username: " << patient_usernames[index] << endl;
        }

        void menu()
        {
            while(1)
            {
                int a;
                cout << endl << "1. View Profile";
                cout << endl << "2. View Nearby Hospitals.";
                cout << endl << "3. View Nearby Pharmacies.";
                cout << endl << "4. Medicine Search.";
                cout << endl << "5. Emegency.";
                cout << endl << "6. Exit" << endl;
                cout << ">";
                cin >> a;

                if(a == 1)
                {
                    viewprofile();
                }
                else if(a == 2)
                {
                    viewnearbyhospitals();
                }
                else if(a == 3)
                {
                    viewnearbypharmacies();
                }
                else if(a == 4)
                {
                    medicinesearch();
                }
                else if(a == 5)
                {
                    emergency();
                }
                else if(a == 6)
                {
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choice!";
                }
            }

        }

        void medicinesearch()
        {
            string hiarr[6][2] = {{"Fever", "Paracetmol"}, {"Cold", "Ceterizine"}, {"Stomach ache", "Cyclopam"}, {"Headache", "Aspirin"}, {"Back pain", "Hydrocodone"}, {"Nausea", "Domperidone"}}; 
            
            cout << endl << "Which Symptom do you have: " << endl;
            int choice;
            for(int i = 0; i < 6; i++)
            {
                cout << i + 1 << ". " << hiarr[i][0] << endl;
            }
            cout << "Enter your choice: ";
            cin >> choice;

            cout << endl << "You can take the following tablet for temporary relief. Consult a Doctor if symptoms persist." << endl;
            cout << hiarr[choice - 1][1] << endl;
        }

        void viewnearbyhospitals()
        {
            string a;
            a = patient_address[index];
            if (a == "Dehgam")
            {
            }
            else if (a == "Gandhinagar")
            {
            }
            else if (a == "Ahemdabad")
            {
            }
            else if (a == "Surat")
            {
            }
            else if (a == "Chiloda")
            {
            }
            else if (a == "Vadodara")
            {
            }
        }

        void viewnearbypharmacies()
        {
            string a;
            a = patient_address[index];
            if (a == "Dehgam")
            {
            }
            else if (a == "Gandhinagar")
            {
            }
            else if (a == "Ahemdabad")
            {
            }
            else if (a == "Surat")
            {
            }
            else if (a == "Chiloda")
            {
            }
            else if (a == "Vadodara")
            {
            }
        }

        void emergency()
        {
            cout << "Not comleted";
        }

};

class doctor : public sira, public patient
{
    protected:
        string citizenid;
        string nmcid;
        string bloodgroup;
        long long uniquecode;
        
        vector <string> doctor_names {"Prasann Barot", "Rabel Guharoy"};
        vector <string> doctor_usernames {"prasann", "rabel"};
        vector <string> doctor_password {"prasann1", "rabel1"};
        vector <long long> doctor_phone1{9924492472, 7980262223};
        vector <long long> doctor_phone2{0, 0}; //0 represnts phone number not provided.
        vector <string> doctor_mail {"prasann.barot@rru.ac.in", "rabel.guharoy@rru.ac.in"};
        vector <string> doctor_address {"Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305", "Rashtriya Raksha University, Lavad, Gandhinagar, Gujarat. - 382305"};
        vector <string> doctor_bloodgroups {"B+", "O+"};
        vector <string> doctor_citizenid{"678677863561", "897765453442"};
        vector <string> doctor_nmcid {"2343er", "4534ty"};
        vector <long long> doctor_uniquecode {33069, 33088};
        
    public:
        int index;
        
        doctor()
        {
            homemenu();
        }

        void homemenu()
        {
            while(1)
            {
                int a;
                cout << endl << "Hello!";
                cout << endl << "1. Login";
                cout << endl << "2. Signup";
                cout << endl << "3. Exit" << endl;
                cout << ">";
                cin >> a;

                if(a == 1)
                {
                    login();
                }
                else if(a == 2)
                {
                    signup();
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

        void login()
        {
            cout << endl <<  "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            for(int i = 0; i < doctor_usernames.size(); i++)
            {
                if(username == doctor_usernames[i] && password == doctor_password[i])
                {
                    cout << endl << "Login Successfull!" <<endl;
                    index = i;
                    menu();
                }
                else
                {
                    cout << "Invalid Credentials!" << endl;
                }
            }
        }

        void signup()
        {
            cout << endl << "Enter your Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter your phone number: ";
            cin >> phone1;
            cout << "Enter your alternate phone number: ";
            cin >> phone2;
            cout << "Enter your mail Id: ";
            cin >> mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter blood group: ";
            cin >> bloodgroup;
            cout << "Enter citizenship ID: ";
            cin >> citizenid;
            cout << "Enter NMC ID: ";
            cin >>nmcid;
            cout << "Enter a Username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            doctor_names.push_back(name);
            doctor_phone1.push_back(phone1);
            doctor_phone2.push_back(phone2);
            doctor_mail.push_back(mail);
            doctor_address.push_back(address);
            doctor_bloodgroups.push_back(bloodgroup);
            doctor_citizenid.push_back(citizenid);
            doctor_nmcid.push_back(nmcid);
            doctor_usernames.push_back(username);
            doctor_password.push_back(password);
            doctor_uniquecode.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "Visit your hospital admin to complete KYC to acces all features of the app!" << endl;
            index = (doctor_usernames.size() - 1);
            homemenu();
        }

        void viewprofile()
        {
            cout << endl << "Name: " << doctor_names[index];
            cout << endl << "Phone Number: " << doctor_phone1[index];
            cout << endl << "Alternate Phone Number: " << doctor_phone2[index];
            cout << endl << "Mail: " << doctor_mail[index];
            cout << endl << "Address: " << doctor_address[index];
            cout << endl << "Blood Group: " << doctor_bloodgroups[index];
            cout << endl << "Citizen ID: " << doctor_citizenid[index];
            cout << endl << "NMC ID: " << doctor_nmcid[index];
            cout << endl << "Username: " << doctor_usernames[index] << endl;
        }

        void menu()
        {
            while(1)
            {
                int a;
                cout << endl << "1. View your Profile";
                cout << endl << "2. View your Patient's Profiles.";
                cout << endl << "3. View your Appointments..";
                cout << endl << "4. Exit" << endl;
                cout << ">";
                cin >> a;

                if(a == 1)
                {
                    viewprofile();
                }
                else if(a == 2)
                {
                    viewpatientsprofile();
                }
                else if(a == 3)
                {
                    viewappointments();
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

        void viewpatientsprofile()
        {
            int choice;
            while(1)
            {
                cout << endl << "Select a patient: ";
                for(int i = 0; i < patient_names.size(); i++)
                {
                    cout << i + 1 << ". " << patient_names[i]; 
                }
                cout << "> ";
                cin >> choice;

                if (choice != patient_names.size() + 1)
                {
                    cout << endl << "Name: " << patient_names[choice - 1];
                    cout << endl << "Phone Number: " << patient_phone1[choice - 1];
                    cout << endl << "Alternate Phone Number: " << patient_phone2[choice - 1];
                    cout << endl << "Mail: " << patient_mail[choice - 1];
                    cout << endl << "Address: " << patient_address[choice - 1];
                    cout << endl << "Blood Group: " << patient_bloodgroups[choice - 1];
                    cout << endl << "Citizen ID: " << patient_citizenid[choice - 1];
                    cout << endl << "Unique Code: " << patient_uniquecode[choice - 1];
                    cout << endl << "Username: " << patient_usernames[choice - 1] << endl;
                }
                else
                {
                    menu();
                }
                    
            }
            
        }

        void viewappointments()
        {
            
        }

};

int main()
{
    A:
        int a;
        cout << endl << "Who are you?";
        cout << endl << "1. Pateint";
        cout << endl << "2. Doctor";
        cout << endl << "3. Admin" << endl;
        cout << ">";
        cin >> a;
        if(a == 1)
        {
            patient p1;
        }
        else if(a == 2)
        {
            doctor d1;
        }
        else if(a == 3)
        {
            //admin a1;
        }
        else
        {
            cout << "Invalid Choice;";
            goto A;
        }
}
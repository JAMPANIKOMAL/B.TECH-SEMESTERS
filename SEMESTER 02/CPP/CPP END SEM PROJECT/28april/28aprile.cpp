//PATIENT CHECK 2, 3 CASES.

#include <iostream>
#include <vector>
using namespace std;

class patient
{
    protected:
        string patient_name;
        string patient_username;
        string patient_password;
        long long patient_phone1;
        long long patient_phone2; // phone2 or emergnecy home contact number
        string patient_mail;
        string patient_address;
        string patient_citizenid;
        string patient_bloodgroup;
        long long patient_uniquecode;

        vector<string> patient_names{"Tejas Prakash Patil", "Aashutosh Thakur", "Jampani Komal"};
        vector<string> patient_usernames{"tejas", "aashutosh", "komal"};
        vector<string> patient_passwords{"tejas1", "aashutosh1", "komal1"};
        vector<long long> patient_phone1s{7720841778, 8102568219, 9182048179};
        vector<long long> patient_phone2s{0, 9825818717, 9704427177}; // 0 represnts phone number not provided.
        vector<string> patient_mails{"tppatil397@gmail.com", "thakuraashutosh13@gmail.com", "jampanikomal2005@gmail.com"};
        vector<string> patient_addresses{"Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421", "Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421", "Home World Hostel, Bhaijipura, Gandhinagar, Gujarat. - 382421"};
        vector<string> patient_bloodgroups{"B+", "O+", "B+"};
        vector<string> patient_citizenids{"230031101611052", "230031101611057", "230031101611054"};
        vector<long long> patient_uniquecodes{23052, 23057, 23054};

    public:
        int index;

        void patient_start()
        {
            patient_homemenu();
        }

        void patient_homemenu()
        {
            while (1)
            {
                int a;
                cout << endl
                    << "Hello!";
                cout << endl
                    << "1. Login";
                cout << endl
                    << "2. Signup";
                cout << endl
                    << "3. Exit" << endl;
                cout << "> ";
                cin >> a;

                if (a == 1)
                {
                    patient_login();
                }
                else if (a == 2)
                {
                    patient_signup();
                }
                else if (a == 3)
                {
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid Choic!";
                }
            }
        }

        void patient_menu()
        {
            while (1)
            {
                int a;
                cout << endl
                    << "1. View Profile";
                cout << endl
                    << "2. View Nearby Hospitals.";
                cout << endl
                    << "3. View Nearby Pharmacies.";
                cout << endl
                    << "4. Medicine Search.";
                cout << endl
                    << "5. Emegency.";
                cout << endl
                    << "6. Exit" << endl;
                cout << "> ";
                cin >> a;

                if (a == 1)
                {
                    patient_viewprofile();
                }
                else if (a == 2)
                {
                    patient_viewnearbyhospitals();
                }
                else if (a == 3)
                {
                    patient_viewnearbypharmacies();
                }
                else if (a == 4)
                {
                    patient_medicinesearch();
                }
                else if (a == 5)
                {
                    patient_emergency();
                }
                else if (a == 6)
                {
                    exit(1);
                }
                else
                {
                    cout << endl
                        << "Invalid Choice!";
                }
            }
        }

        void patient_login()
        {
            cout << endl
                << "Enter Username: ";
            cin >> patient_username;
            cout << "Enter Password: ";
            cin >> patient_password;
            int flag = 0;

            for (int i = 0; i < patient_usernames.size(); i++)
            {
                if (patient_username == patient_usernames[i] && patient_password == patient_passwords[i])
                {
                    cout << endl << "Login Successfull!" << endl;
                    index = i;
                    flag = 1;
                    patient_menu();
                }
            }

            if (flag == 0)
            {
                cout << "Invalid Credentials!" << endl;
                patient_homemenu();
            }
        }

        void patient_signup()
        {
            cout << endl
                << "Enter your Name: ";
            cin.ignore();
            getline(cin, patient_name);
            cout << "Enter your phone number: ";
            cin >> patient_phone1;
            cout << "Enter your alternate [Emergency] phone number: ";
            cin >> patient_phone2;
            cout << "Enter your mail Id: ";
            cin >> patient_mail;
            cout << "Address: ";
            cin.ignore();
            getline(cin, patient_address);
            cout << "Enter blood group: ";
            cin >> patient_bloodgroup;
            cout << "Enter citizenship ID: ";
            cin >> patient_citizenid;
            cout << "Enter a Username: ";
            cin >> patient_username;
            cout << "Enter password: ";
            cin >> patient_password;

            patient_names.push_back(patient_name);
            patient_phone1s.push_back(patient_phone1);
            patient_phone2s.push_back(patient_phone2);
            patient_mails.push_back(patient_mail);
            patient_addresses.push_back(patient_address);
            patient_bloodgroups.push_back(patient_bloodgroup);
            patient_citizenids.push_back(patient_citizenid);
            patient_usernames.push_back(patient_username);
            patient_passwords.push_back(patient_password);
            patient_uniquecodes.push_back(rand() % 100);

            cout << endl << "Sign Up Succesfull!" << endl << "Visit nearest hospital to complete KYC to acces all features of the app!" << endl;
            index = (patient_usernames.size() - 1);

            patient_homemenu();
        }

        void patient_viewprofile()
        {
            cout << endl << "Name: " << patient_names[index];
            cout << endl << "Phone Number: " << patient_phone1s[index];
            cout << endl << "Alternate Phone Number: " << patient_phone2s[index];
            cout << endl << "Mail: " << patient_mails[index];
            cout << endl << "Address: " << patient_addresses[index];
            cout << endl << "Blood Group: " << patient_bloodgroups[index];
            cout << endl << "Citizen ID: " << patient_citizenids[index];
            cout << endl << "Unique Code: " << patient_uniquecodes[index];
            cout << endl << "Username: " << patient_usernames[index] << endl;
        }

       void patient_medicinesearch()
        {
            string hiarr[6][2] = {{"Fever", "Paracetmol"}, {"Cold", "Ceterizine"}, {"Stomach ache", "Cyclopam"}, {"Headache", "Aspirin"}, {"Back pain", "Hydrocodone"}, {"Nausea", "Domperidone"}};

            cout << endl<< "Which Symptom do you have: " << endl;
            int choice;
            for (int i = 0; i < 6; i++)
            {
                cout << i + 1 << ". " << hiarr[i][0] << endl;
            }
            cout << "Enter your choice: ";
            cin >> choice;

            if(choice > 7)
            {
                cout << endl << "Invalid Choice! << endl";
                patient_menu();
                return;
            }

            cout << endl << "You can take the following tablet for temporary relief. Consult a Doctor if symptoms persist." << endl;
            cout << hiarr[choice - 1][1] << endl;
        }

        void patient_viewnearbyhospitals()
        {
            cout << endl << "Where do you live?";
            int choice;
            while (1)
            {
                cout << endl << "1. Dahegam";
                cout << endl << "2. Gandhinagar";
                cout << endl << "3. Ahmedabad";
                cout << endl << "4. Surat";
                cout << endl << "5. Vadodara";
                cout << endl << "6. Exit" << endl;
                cout << "> ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                    {
                        cout << endl << "Life Care Hospital: \"16 Shreenath Arcade Dehgam, Dahegam, Gujarat 382305\"" << endl;
                        return;
                    }

                    case 2:
                    {
                        cout << endl << "Apollo Hospital: \"Plot no. 1555, GH Rd, near GH 2 Circle, Sector 6, Gandhinagar, Gujarat 382006\"" << endl;
                        return;
                    }
                        
                    case 3:
                    {
                        cout << endl << "Sterling Hospital: \"Shop No 12 & 13, Ground Floor, Kanam 2, near Reliance Chowkdi, Kudasan, Ahmedabad, Gujarat 382421\"" << endl;
                        return;
                    }
                    case 4:
                    {
                        cout << endl << "Surat General Hospital: \"Mann Complex, 6, Anand Mahal Rd, Opposite Shree Ram Petrol Pump, Adajan, Surat, Gujarat 395009\"" << endl;
                        return;
                    }
                    case 5:
                    {
                        cout << endl << "Sunshine Global Hospital: \"Shop No 7, Om Complex, Vasna Rd, near Taksh Complex, Shivashraya Society, Tandalja, Vadodara, Gujarat 390015\"" << endl;
                        return;
                    } 
                    case 6:
                    {
                        patient_menu();
                        return;
                    }
                        
                    default:
                    {
                        cout << endl << "Invalid choice or few places are still left to update. Sorry for the inconvenience!" << endl;
                        return;
                    }   
                }
            }
        }

        void patient_viewnearbypharmacies()
        {
            cout << endl << "Where do you live?";
            int choice;
            while (1)
            {
                cout << endl << "1. Dahegam";
                cout << endl << "2. Gandhinagar";
                cout << endl << "3. Ahmedabad";
                cout << endl << "4. Surat";
                cout << endl << "5. Vadodara";
                cout << endl << "6. Exit" << endl;
                cout << "> ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                    {
                        cout << endl << "PharmEasy Medicine Point: \"16 Shreenath Arcade Dehgam, Dahegam, Gujarat 382305\"" << endl;
                        return;
                    } 
                    case 2:
                    {
                        cout << endl << "Apollo Pharmacy: \"Plot no. 1555, GH Rd, near GH 2 Circle, Sector 6, Gandhinagar, Gujarat 382006\"" << endl;
                        return;
                    }
                    case 3:
                    {
                        cout << endl << "Apollo Pharmacy: \"Shop No 12 & 13, Ground Floor, Kanam 2, near Reliance Chowkdi, Kudasan, Ahmedabad, Gujarat 382421\"" << endl;
                        return;
                    }
                    case 4:
                    {
                        cout << endl << "Apollo Pharmacy: \"Mann Complex, 6, Anand Mahal Rd, Opposite Shree Ram Petrol Pump, Adajan, Surat, Gujarat 395009\"" << endl;
                        return;
                    }
                    case 5:
                    {                    
                        cout << endl << "Medkart Pharmacy: \"Shop No 7, Om Complex, Vasna Rd, near Taksh Complex, Shivashraya Society, Tandalja, Vadodara, Gujarat 390015\"" << endl;
                        return;

                    }
                    case 6:
                    {
                        patient_menu();
                        return;
                    }  
                    default:
                    {
                        cout << endl << "Invalid choice or few places are still left to update. Sorry for the inconvenience!" << endl;
                        return;
                    }
                }
            }
        }

        void patient_emergency()
        {
            cout << endl << "Code Under Progress!" << endl;
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
            patient p1;
            p1.patient_start();
        }
        else if (a == 2)
        {
            //doctor d1;
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

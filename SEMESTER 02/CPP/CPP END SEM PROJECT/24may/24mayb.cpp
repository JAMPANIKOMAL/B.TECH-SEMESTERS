void viewprofile()
        {
            int choice;
            while(1)
            {
                cout << endl << "Select a choice from the following: ";
                cout << endl << "1. View Profile.";
                cout << endl << "2. Edit Profile";
                cout << endl << "3. Exit";
                cout << endl << "Enter your choice: ";
                cin >> choice;

                switch(choice)
                {
                    case 1:
                    {
                        
                    }
                }
                if (n == 1)
                {
                    int num;
                    long long txt;
                    string a, b, adr;
                    cout << "\n1.Name\n2.Address\n3.Phone Number\n4.citizenship\n5.Blood Group\n6.Mail ID\n7.Medicine\n8.User ID\n9.Password\n10.Parents Phone\n";
                    cin >> num;
                    if (num == 1)
                    {
                        cout << "Enter your Name: ";
                        cin >> a >> b;
                        f_name[size] = a;
                        l_name[size] = b;
                    }
                    else if (num == 2)
                    {
                        cout << "Enter New Address: ";
                        cin >> adr;
                        address[size] = adr;
                    }
                    else if (num == 3)
                    {
                        cout << "Enter New Number: ";
                        cin >> txt;
                        phone[size] = txt;
                        txt = 0;
                    }
                    else if (num == 4)
                    {
                        cout << "Enter Chitizenship: ";
                        cin >> txt;
                        phone[size] = txt;
                        txt = 0;
                    }
                    else if (num == 5)
                    {
                        cout << "Enter Blood Group: ";
                        cin >> adr;
                        blood[size] = adr;
                    }
                    else if (num == 6)
                    {
                        cout << "Enter New Email: ";
                        cin >> adr;
                        mail[size] = adr;
                    }
                    else if (num == 7)
                    {
                        cout << "Enter New Number: ";
                        cin >> adr;
                        medicine[size] = adr;
                    }
                    else if (num == 8)
                    {
                        cout << "Enter New Number: ";
                        cin >> txt;
                        iD[size] = txt;
                        txt = 0;
                    }
                    else if (num == 9)
                    {
                        cout << "Enter New Number: ";
                        cin >> adr;
                        password[size] = adr;
                    }
                    else if (num == 10)
                    {
                        cout << "Enter Parents Number: ";
                        cin >> txt;
                        parentspn[size] = txt;
                        txt = 0;
                    }
                }
            else if (n == 2)
            {
                cout << "Name: " << f_name[size] << " " << l_name[size];
                cout << "Address: " << address[size];
                cout << "Phone Number: " << phone[size];
                cout << "Email ID: " << mail[size];
                cout << "Unique ID: " << unique[size];
                cout << "Citizenship: " << citizenID[size];
                cout << "Parents Number: " << parentspn[size];
                cout << "Medicine: " << medicine[size];
                cout << "Blood Group: " << blood[size];
            }
            else if (n == 3)
            {
                exit(1);
            }
            else
            {
                cout << "Invalid choice\n";
                exit(1);
            }
        }
            }
            
        };
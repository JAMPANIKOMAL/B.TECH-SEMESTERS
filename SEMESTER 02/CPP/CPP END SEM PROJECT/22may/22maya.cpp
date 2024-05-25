#include <iostream>
using namespace std;
#define maxsize 10
#define docsize 10
#define hossize 10
class sira
{
private:
    // Patient
    int size;
    long long phone[maxsize], citizenID[maxsize], unique[maxsize], parentspn[maxsize];
    string f_name[maxsize], l_name[maxsize], blood[maxsize], medicine[maxsize], mail[maxsize], address[maxsize];
    int count = 0;
    int iD[maxsize];
    string password[maxsize];
    // Doctor
    int size_doc;
    long long phone1[docsize], citizenID1[docsize], unique1[docsize], parentspn1[docsize], _NMC_number1[docsize];
    string f_name1[docsize], l_name1[docsize], blood1[docsize], medicine1[docsize], mail1[docsize], address1[docsize];
    int count1 = 0;
    int iD1[docsize];
    string password1[docsize];
    // Hospital

public:
    int loginPatient();
    void profilepatient();
    void medicalSer();
    void nearbyhos();
    void nearbyphar();
    void emergency();
    void signUpPatient();
    
    int loginDoctor();
    void profileDoctor();
    void visitprof();
    void signUpDoctor();
    void loginAdmin();
    void hospitalprofile();
    void docpro();
    void emergencycase();
    void signUpAdmin();
};
int sira::loginPatient()
{
    int i, j, k = 3;
    int x;
start:
    string y;
    for (i = 0; i < maxsize; i++)
    {
        cout << "Enter your user ID: ";
        cin >> x;
        cout << "Enter Password: ";
        cin >> y;
        for (int j = 0; j < maxsize; j++)
        {
            if (x == iD[j] && y == password[j])
            {
                size = j;
                return 1;
            }
        }
        {
            if (k == 0)
            {
                cout << "Your account has been blocked!\n";
                exit(1);
            }
            else
            {
                cout << "You have " << k-- << " attempt left\nYour account will be blocked\n";
            }
            goto start;
        }
    }
}

void sira::profilepatient()
{
    int n;
start:
    cout << "1-Edit Profile\n2-Check Profile\n3-Exit\n";
    cin >> n;
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
void sira::medicalSer()
{
    string hiarr[6][2] = {{"Fever", "Paracetmol"}, {"Cold", "Ceterizine"}, {"Stomach ache", "Cyclopam"}, {"Headache", "Aspirin"}, {"Back pain", "Hydrocodone"}, {"Nausea", "Domperidone"}}; 
    
    cout << "Which Symptom do you have: " << endl;
    int choice;
    for(int i = 0; i < 6; i++)
    {
        cout << i + 1 << ". " << hiarr[i][0] << endl;
    }
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "You can take the following tablet for temporary relief. Consult a Doctor if symptoms persist." << endl;
    cout << hiarr[choice][1] << endl;
}
void sira::nearbyhos()
{
    string a;
    a = address[size];
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
void sira::nearbyphar()
{
    string a;
    a = address[size];
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
void sira::emergency()
{
}
void sira::signUpPatient()
{
    if (count == docsize)
    {
        cout << "No space to enter more:\n";
    }
    else
    {
        string a, b, c, d, e, k, l;
        double f, g, h, i, j;
        cout << "Enter your Name: ";
        cin >> a >> b;
        cout << "Adress: ";
        cin >> l;
        cout << "Enter blood group: ";
        cin >> c;
        cout << "Enter if consuming any medicine else write NO: ";
        cin >> d;
        cout << "Enter your mail Id: ";
        cin >> k;
        cout << "Enter your number: ";
        cin >> j;
        cout << "Enter citizenship ID: ";
        cin >> f;
        cout << "Enter Default(Phone) Number: ";
        cin >> g;
        cout << "Your a unique Number: ";
        int abc = 10000;
        cout << rand() % abc << endl;
        cout << "Enter a user ID(must be greater than 4 digit): ";
        cin >> i;
        cout << "Enter password: ";
        cin >> e;
        f_name[count] = a;
        l_name[count] = b;
        address[count] = l;
        blood[count] = c;
        medicine[count] = d;
        mail[count] = k;
        phone[count] = j;
        citizenID[count] = f;
        parentspn[count] = g;
        unique[count] = h;
        iD[count] = i;
        password[count] = e;
        count++;
    }
}
int sira::loginDoctor()
{
    int i, j, k = 3;
    int x;
start:
    string y;
    for (i = 0; i < docsize; i++)
    {
        cout << "Enter your user ID: ";
        cin >> x;
        cout << "Enter Password: ";
        cin >> y;
        for (int j = 0; j < docsize; j++)
        {
            if (x == iD[j] && y == password[j])
            {
                size = j;
                return 1;
            }
        }
        {
            if (k == 0)
            {
                cout << "Your account has been blocked!\n";
                exit(1);
            }
            else
            {
                cout << "You have " << k-- << " attempt left\nYour account will be blocked\n";
            }
            goto start;
        }
    }
}
void sira::profileDoctor()
{
    int n;
start:
    cout << "1-Edit Profile\n2-Check Profile\n3-Exit\n";
    cin >> n;
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
            f_name1[size] = a;
            l_name1[size] = b;
        }
        else if (num == 2)
        {
            cout << "Enter New Address: ";
            cin >> adr;
            address1[size] = adr;
        }
        else if (num == 3)
        {
            cout << "Enter New Number: ";
            cin >> txt;
            phone1[size] = txt;
            txt = 0;
        }
        else if (num == 4)
        {
            cout << "Enter Chitizenship: ";
            cin >> txt;
            phone1[size] = txt;
            txt = 0;
        }
        else if (num == 5)
        {
            cout << "Enter Blood Group: ";
            cin >> adr;
            blood1[size] = adr;
        }
        else if (num == 6)
        {
            cout << "Enter New Email: ";
            cin >> adr;
            mail1[size] = adr;
        }
        else if (num == 7)
        {
            cout << "Enter New Number: ";
            cin >> adr;
            medicine1[size] = adr;
        }
        else if (num == 8)
        {
            cout << "Enter New Number: ";
            cin >> txt;
            iD1[size] = txt;
            txt = 0;
        }
        else if (num == 9)
        {
            cout << "Enter New Number: ";
            cin >> adr;
            password1[size] = adr;
        }
        else if (num == 10)
        {
            cout << "Enter Parents Number: ";
            cin >> txt;
            parentspn1[size] = txt;
            txt = 0;
        }
    }
    else if (n == 2)
    {
        cout << "Name: " << f_name1[size] << " " << l_name1[size];
        cout << "Address: " << address1[size];
        cout << "Phone Number: " << phone1[size];
        cout << "Email ID: " << mail1[size];
        cout << "Unique ID: " << unique1[size];
        cout << "Citizenship: " << citizenID1[size];
        cout << "Parents Number: " << parentspn1[size];
        cout << "Medicine: " << medicine1[size];
        cout << "Blood Group: " << blood1[size];
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
void sira::visitprof()
{
}
void sira::signUpDoctor()
{
    if (count1 == docsize)
    {
        cout << "No space to enter more.\n";
    }
    else
    {
        string a, b, c, d, e, k, l;
        double f, g, h, i, j, m;
        cout << "Enter your Name: ";
        cin >> a >> b;
        cout << "Enter your NMC number: ";
        cin >> m;
        cout << "Address: ";
        cin >> l;
        cout << "Enter blood group: ";
        cin >> c;
        cout << "Enter if consuming any medicine (else write NO): ";
        cin >> d;
        cout << "Enter your mail Id: ";
        cin >> k;
        cout << "Enter your number: ";
        cin >> j;
        cout << "Enter citizenship ID: ";
        cin >> f;
        cout << "Enter Default (Phone) Number: ";
        cin >> g;
        cout << "Your unique Number: ";
        int abc = 10000;
        cout << rand() % abc << endl;
        cout << "Enter a user ID (must be greater than 4 digits): ";
        cin >> i;
        cout << "Enter password: ";
        cin >> e;
        f_name1[count1] = a;
        l_name1[count1] = b;
        address1[count1] = l;
        blood1[count1] = c;
        medicine1[count1] = d;
        mail1[count1] = k;
        phone1[count1] = j;
        citizenID1[count1] = f;
        parentspn1[count1] = g;
        unique1[count1] = h;
        iD1[count1] = i;
        password1[count1] = e;
        _NMC_number1[count1] = m;
        count1++;
    }
}
void sira::loginAdmin()
{
}
void sira::hospitalprofile()
{
}
void sira::docpro()
{
}
void sira::emergencycase()
{
}
void sira::signUpAdmin()
{
}
int main()
{
    sira s1[1];
    int choose, i = 0, j = 0;
    int choice;
start:
    cout << "1-Patient\n2-Doctor\n3-Admin\n4-Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "1-Login\n2-SignUp\n";
        cin >> choose;
        if (choose == 1)
        {
            s1[j].loginPatient();
            int profile;
        stop:
            cout << "1-Profile\n2-Medical Search\n3-Nearby Hospital\n4-Nearby Pharmacy\n5-Emergency\n6-Exit\n7-Goto start\n8-LogOut\n";
            cin >> profile;
            switch (profile)
            {
            case 1:
            {
                s1[j].profilepatient();
                goto stop;
            }
            case 2:
            {
                s1[j].medicalSer();
                goto stop;
            }
            case 3:
            {
                s1[j].nearbyhos();
                goto stop;
            }
            case 4:
            {
                s1[j].nearbyphar();
                goto stop;
            }
            case 5:
            {
                s1[j].emergency();
                goto stop;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                goto start;
            }
            case 8:
            {
                goto start;
            }
            default:
            {
                cout << "Invalid Choise! Please choose it again!\n";
                goto start;
            }
            }
        }
        else if (choose == 2)
        {
            s1[j].signUpPatient();
            goto start;
        }
        else
        {
            cout << "Invalid choice!Please Choose it again!\n";
            goto start;
        }
    }
    case 2:
    {
        int choose;
        cout << "1-Login\n2-SignUp\n";
        cin >> choose;
        if (choose == 1)
        {
            s1[j].loginDoctor();
        turn:
            int option;
            cout << "1-Profile\n2-Patient Profile\n3-Medical Search\n4-Nearby Hospital\n5-Nearby Pharmacy\n6-Emergency\n7-Exit\n8-GoTo start\n9-LogOut\n";
            cin >> option;
            switch (option)
            {
            case 1:
            {
                s1[j].profileDoctor();
                goto turn;
            }
            case 2:
            {
                s1[j].visitprof();
                goto turn;
            }
            case 3:
            {
                s1[j].medicalSer();
                goto turn;
            }
            case 4:
            {
                s1[j].nearbyhos();
                goto turn;
            }
            case 5:
            {
                s1[j].nearbyphar();
                goto turn;
            }
            case 6:
            {
                s1[j].emergency();
                goto turn;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                goto start;
            }
            case 9:
            {
                goto start;
            }
            default:
            {
                cout << "Invalid Choice! Please choose it again!\n";
                goto start;
            }
            }
        }
        else if (choose == 2)
        {
            s1[j].signUpDoctor();
            goto start;
        }
        else
        {
            cout << "Invalid Input: Please Choose it again!\n";
            goto start;
        }
    }
    case 3:
    {
        int choose;
    step:
        cout << "1-Login\n2-SignUp\n";
        cin >> choose;
        if (choose == 1)
        {
            s1[j].loginAdmin();
        work:
            int hos;
            cout << "1-Hospital Profile\n2-Doctor Profile\n3-Emergency Case\n4-Exit\n5-GoTo start\n6-LogOut";
            cin >> hos;
            switch (hos)
            {
            case 1:
            {
                s1[j].hospitalprofile();
                goto work;
            }
            case 2:
            {
                s1[j].docpro();
                goto work;
            }
            case 3:
            {
                s1[j].emergencycase();
                goto work;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                goto start;
            }
            case 6:
            {
                goto start;
            }
            default:
            {
                cout << "Invalid Choice! Please choose it again!\n";
                goto start;
            }
            }
        }
        else if (choose == 2)
        {
            s1[j].signUpAdmin();
            goto start;
        }
        else
        {
            cout << "Invalid  Choice: Please Choose it again!\n";
            goto start;
        }
    }
    case 4:
    {
        break;
    }
    default:
    {
        cout << "Invalid Choice! Please Choose it again!\n";
        goto start;
    }
    }
}
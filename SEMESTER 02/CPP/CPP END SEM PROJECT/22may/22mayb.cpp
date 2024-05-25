//SEARCH BAR

#include <iostream>
using namespace std;

void search_bar()
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

int main()
{
    search_bar();
}
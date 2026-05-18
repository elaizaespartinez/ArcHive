#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

const int maxrow = 100;

string StuName[maxrow] = {};
string SRCode[maxrow] = {};
string Prog[maxrow] = {};
string Pnum[maxrow] = {};
string Addr[maxrow] = {};

void OpenFile() {
    string line;
    ifstream myfile("D:\CSProject\STUDENTFILES.txt");

    if (myfile.is_open()) {
        int x = 0;
        while (getline(myfile, line)) {
            if (line.empty()) continue;


            SRCode[x] = line.substr(0, 18);
            StuName[x] = line.substr(18, 40);
            Prog[x] = line.substr(58, 25);
            Pnum[x] = line.substr(83, 20);
            Addr[x] = line.substr(103);


            SRCode[x] = SRCode[x].substr(0, SRCode[x].find_last_not_of(' ') + 1);
            StuName[x] = StuName[x].substr(0, StuName[x].find_last_not_of(' ') + 1);
            Prog[x] = Prog[x].substr(0, Prog[x].find_last_not_of(' ') + 1);
            Pnum[x] = Pnum[x].substr(0, Pnum[x].find_last_not_of(' ') + 1);
            Addr[x] = Addr[x].substr(0, Addr[x].find_last_not_of(' ') + 1);

            x++;
        }

        myfile.close();
    } else {
        cout << "Unable to open file!" << endl;
    }
}

void AddRecord(){
    char name[50];
    char srcode[10];
    char prog[50];
    char pnum[20];
    char add[50];

    cin.ignore();

    cout << "Student SR Code: ";
    cin.getline(srcode, 10);
    cout << "Student Name (Last name, First name M.I): ";
    cin.getline(name, 50);
    cout << "Program & Section (BSCS-1101): ";
    cin.getline(prog, 50);
    cout << "Phone Number: ";
    cin.getline(pnum, 20);
    cout << "Address(Brgy, City/Municipality): ";
    cin.getline(add, 50);

    for (int i = 0; name[i] != '\0'; i++)
        {
        name[i] = toupper(name[i]);
        }
    for (int i = 0; prog[i] != '\0'; i++)
        {
        prog[i] = toupper(prog[i]);
        }
    for (int i = 0; add[i] != '\0'; i++)
        {
        add[i] = toupper(add[i]);
        }

    for (int x = 0; x < maxrow; x++)
    {
        if (SRCode[x] == "\0")
        {
            SRCode[x] = srcode;
            StuName[x] = name;
            Prog[x] = prog;
            Pnum[x] = pnum;
            Addr[x] = add;

            break;
        }
    }
}


void ListRecord() {
    system("CLS");
    cout << "Current Record/s" << endl;
    cout << "=========================================================================================================================================================" << endl;

    int counter = 0;
    cout << left; // Align all columns to the left
    cout << setw(6) << "No."
         << setw(19) << "|SRCODE"
         << setw(41) << "|STUDENT NAME"
         << setw(26) << "|Program"
         << setw(21) << "|Phone Number"
         << "|Address" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int x = 0; x < maxrow; x++) {
        if (SRCode[x] != "\0") {
            counter++;

            cout << left; // Ensure all data is left-aligned
            cout << setw(8) << counter
                 << setw(19) << SRCode[x]
                 << setw(41) << StuName[x]
                 << setw(26) << Prog[x]
                 << setw(21) << Pnum[x]
                 << Addr[x] << endl; // Address column does not need setw as it's the last column
        }
    }


    if (counter == 0) {

        cout << "NO RECORDS FOUND!!" << endl;
    }

        cout << "=========================================================================================================================================================" << endl;
}

void SearchRecord(string search) {
    system("CLS");
    cout << "Current Record/s" << endl;
    cout << "=========================================================================================================================================================" << endl;

    int counter = 0;
    cout << left; // Align all columns to the left
    cout << setw(6) << "No. "
         << setw(19) << "|SRCODE "
         << setw(41) << "|STUDENT NAME "
         << setw(26) << "|Program "
         << setw(21) << "|Phone Number "
         << "|Address" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int x = 0; x < maxrow; x++) {
        if (SRCode[x] == search) {
            counter++;
            cout << left; // Ensure all data is left-aligned
            cout << setw(8) << counter
                 << setw(19) << SRCode[x]
                 << setw(41) << StuName[x]
                 << setw(26) << Prog[x]
                 << setw(21) << Pnum[x]
                 << Addr[x] << endl;
            break; // Exit loop after finding the record
        }
    }

    if (counter == 0) {
        cout << "NO RECORD FOUND!" << endl;
    }

    cout << "=========================================================================================================================================================" << endl;
}


void UpdateRecord(string search){
    system("CLS");
    char name[50];
    char srcode[10];
    char prog[50];
    char pnum[20];
    char add[50];

    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (SRCode[x] == search)
        {
            counter++;


            cout << "New SR Code: ";
            cin.getline(srcode, 10);

            SRCode[x] = srcode;


            cout << "Student Name (Last name, First name, M.I): ";
            cin.getline(name, 50);

            for (int i = 0; name[i] != '\0'; i++)
                {
                    name[i] = toupper(name[i]);
                }

              StuName[x] = name;


            cout << "New Program: ";
            cin.getline(prog, 50);

            for (int i = 0; prog[i] != '\0'; i++)
                {
                    prog[i] = toupper(prog[i]);
                }


            Prog[x] = prog;

            cout << "New Phone Number: ";
            cin.getline(pnum, 20);

            Pnum[x] = pnum;

            cout << "New Address: ";
            cin.getline(add, 50);

             for (int i = 0; add[i] != '\0'; i++)
                {
                    add[i] = toupper(add[i]);
                }

            Addr[x] = add;

            cout << "----------------------------------" << endl;
            cout << "Update Successfull!" << endl;
            cout << "==================================" << endl;
            break;
        }
    }

    if (counter == 0){
        cout << "SRCODE DOES NOT EXIST!" << endl;
        cout << "====================================================" << endl;
    }
}

void DeleteRecord(string search) {
    int counter = 0;
    for (int x = 0; x < maxrow; x++) {
        if (SRCode[x] == search) {
            counter++;

            for (int y = x; y < maxrow - 1; y++) {
                SRCode[y] = SRCode[y + 1];
                StuName[y] = StuName[y + 1];
                Prog[y] = Prog[y + 1];
                Pnum[y] = Pnum[y + 1];
                Addr[y] = Addr[y + 1];
            }

            SRCode[maxrow - 1] = "";
            StuName[maxrow - 1] = "";
            Prog[maxrow - 1] = "";
            Pnum[maxrow - 1] = "";
            Addr[maxrow - 1] = "";

            cout << "--------------------------------" << endl;
            cout << "Successfully Deleted!" << endl;
            cout << "================================" << endl;
            break;
        }
    }
    if (counter == 0) {
        cout << "====================================================" << endl;
        cout << "SR CODE DOES NOT EXIST!" << endl;
        cout << "====================================================" << endl;
    }
}


void SaveData() {
    ofstream myfile;
    myfile.open("D:\CSProject\STUDENTFILES.txt");

    if (!myfile.is_open()) {
        cout << "Error: Unable to save data to file!" << endl;
        return;
    }

    for (int x = 0; x < maxrow; x++) {
        if (SRCode[x] == "\0") {
            break;
        } else {
            // Write data in a properly aligned format
            myfile << left
                   << setw(18) << SRCode[x]
                   << setw(40) << StuName[x]
                   << setw(25) << Prog[x]
                   << setw(20) << Pnum[x]
                   << Addr[x] << endl; // Address column doesn't need setw as it's the last
        }
    }

    myfile.close();
}

int main (){

    cout <<  "MENU\n";
    int option;
    string srcode;
    system("CLS");
    OpenFile();

    do {
    cout << "1-Creat Record" << endl;
    cout << "2-Update Record" << endl;
    cout << "3-Delete Record" << endl;
    cout << "4-Search Record" << endl;
    cout << "5-Display All Record" << endl;
    cout << "6-Exit and Save to Textfile" << endl;
    cout << "===============================" << endl;

    cout << "Select Option >>";
    cin >> option;
    cout << "===============================" << endl;


    switch (option)
    {
        case 1:
            AddRecord();
            system("CLS");
            break;

        case 2:
            cin.ignore();
            cout << "Search by SR Code: ";
            getline(cin, srcode);
            UpdateRecord(srcode);
            break;

        case 3:
            cin.ignore();
            cout << "Delete by SR Code: ";
            getline(cin, srcode);
            DeleteRecord(srcode);
            cin.ignore();
            system("CLS");
            break;

        case 4:
            cin.ignore();
            cout << "Search by SR Code: ";
            getline(cin, srcode);
            SearchRecord(srcode);
            break;

        case 5:
            ListRecord();
            break;
    }

    } while (option !=6);

    SaveData();
    cout << "Exit....Saving the Data to File!" << endl;
    return 0;
}


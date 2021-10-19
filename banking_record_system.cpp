#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class account_query
{
    char acc_numb[20];
    char fname[10];
    char lname[10];
    float total_balance;

public:
    void read_data();
    void show_data();
    void write_record();
    void read_record();
    void search_record();
    void edit_record();
    void delete_record();
};

void account_query::read_data()
{
    cout << "\n Enter Account Number: ";
    cin >> acc_numb;
    cout << "\n Enter First Name: ";
    cin >> fname;
    cout << "\n Enter Last Name: ";
    cin >> lname;
    cout << "\n Enter the total balance: ";
    cin >> total_balance;
    cout << endl;
}

void account_query::show_data()
{
    cout << "\n Account Number: " << acc_numb << endl;
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Account Balance: " << total_balance << endl;
    cout << "------------------------------------------------" << endl;
}

void account_query::write_record()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary | ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void account_query::read_record()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "Error in Opening! File Not Found!" << endl;
        return;
    }
    cout << "\n ****Data from file****" << endl;
    while (!infile.eof())
    {
        if (infile.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            show_data();
        }
    }
    infile.close();
}

void account_query::search_record()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if (!infile)
    {
        cout << "Error in opening! File Not Found! " << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file.";
    cout << "\n Enter record number to search: ";
    cin >> n;
    infile.seekg((n - 1) * sizeof(*this));
    infile.read(reinterpret_cast<char *>(this), sizeof(*this));
    show_data();
}

void account_query::edit_record()
{
    int n;
    fstream iofile;
    iofile.open("record.bank", ios::in | ios::binary);
    if (!iofile)
    {
        cout << "Error in opening! File Not Found! " << endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter record number to edit";
    cin >> n;
    iofile.seekg((n - 1) * sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this), sizeof(*this));
    cout << "Record " << n << " has following data" << endl;
    show_data();
    iofile.close();
    iofile.open("record.bank", ios::out | ios::in | ios::binary);
    iofile.seekp((n - 1) * sizeof(*this));
    cout << "\n Enter data to modify " << endl;
    read_data();
    iofile.write(reinterpret_cast<char *>(this), sizeof(*this));
}

void account_query::delete_record()
{
    int n;
    ifstream infile;
    infile.open("record.open", ios::binary);
    if (!infile)
    {
        cout << "Error in opening! File Not Found! " << endl;
        return;
    }
    infile.seekg(0, ios::end);
    int count = infile.tellg() / sizeof(*this);
    cout << "\n There are " << count << " record in the file";
    cout << "\n Enter record number to delete";
    cin >> n;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out | ios::binary);
    infile.seekg(0);
    for (int i = 0; i < count; i++)
    {
        infile.read(reinterpret_cast<char *>(this), sizeof(*this));
        if (i == (n - 1))
            continue;
        tmpfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.bank");
    rename("tmpfile.bank", "record.bank");
}

int main()
{
    account_query Ac;
    int choice;
    cout << "********Account Information System*********";
    while (true)
    {
        cout << "Select one opetion below ";
        cout << "\n 1. Add record to file";
        cout << "\n 2. Show record to file";
        cout << "\n 3. Search record from file";
        cout << "\n 4. Update record to file";
        cout << "\n 5. Delete record to file";
        cout << "\n 6. Quit";
        cout << "\n Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Ac.write_record();
            break;
        case 2:
            Ac.read_record();
            break;
        case 3:
            Ac.read_record();
            break;
        case 4:
            Ac.edit_record();
            break;
        case 5:
            Ac.delete_record();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n Enter correct choice";
            break;
        }
    }
    system("pause");
    return 0;
}
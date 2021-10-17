#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int admin_login();
int admin_view();
int student_view();
int student_login();
int get_all_std_by_roll();
int delete_all_std();
int delete_std_byroll();
int check_list_of_std_rsg();
int check_presence_roll();
int list_present_std_count();
int check_credentials(string s_name, string passw);
int get_list_std_wt_presence_count();
int registered_std();
int admin_login();
int register_std();
int mark_attedn(string username);
int count_attend(string username);
int delay();

int admin_login()
{
    system("cls");
    cout << "\n------------ADMIN LOGIN------------";
    string username, passw;
    cout << "\n Enter username: ";
    cin >> username;
    cout << "\n Enter password: ";
    cin >> passw;
    if (username == "admin" && passw == "admin02")
    {
        admin_view();
        getchar();
        delay();
    }
    else
    {
        cout << "\n Invalid Credentials";
        cout << "\n Press any key for main menu";
        getchar();
        getchar();
    }
    return 0;
}

int admin_view()
{
    int goBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1. Register a student.";
        cout << "\n 2. Delete a student name registered.";
        cout << "\n 3. Delete student by roll number.";
        cout << "\n 4. Check lists of student registered by username.";
        cout << "\n 5. Check presence count of any student by roll number.";
        cout << "\n 6. List of student with their attendence count.";
        cout << "\n 0. Go back";
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            registered_std();
            break;

        case 2:
            delete_all_std();
            break;

        case 3:
            delete_std_byroll();
            break;

        case 4:
            check_list_of_std_rsg();
            break;

        case 5:
            int check_presence_roll();
            break;
        case 6:
            int list_present_std_count();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice entered. Enter again";
        }
        if (goBack == 1)
            break;
    }
    return 0;
}

int student_view()
{
    cout << "-------------STUDENT LOGIN-----------";
    string username, passw;
    cout << "\n Enter username: ";
    cin >> username;
    cout << "\n Enter password: ";
    cin >> passw;

    int res = check_credentials(username, passw);
    if (res == 0)
    {
        cout << "Invalid Credentials";
        cout << "Press any key for the main menu";
        getchar();
        getchar();
        return 0;
    }
    int goBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1. Mark attendence for today";
        cout << "\n 2. Count my attendence";
        cout << "\n 3. Go back <- \n";
        int choice;
        switch (choice)
        {
        case 1:
            mark_attedn(username);
            break;
        case 2:
            count_attend(username);
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "Invalid choice. Enter again...";
            getchar();
        }
        if (goBack == 1)
        {
            break;
        }
    }
}

int student_login()
{
    system("cls");
    cout << "\n------------STUDENT LOGIN --------------";
    student_view();
    delay();
    return 0;
}

int check_credentials(string s_name, string passw)
{
    ifstream read;
    read.open("db.dat");
    if (read)
    {
        int recordFound = 0;
        string line;
        string temp = "username" + passw + ".dat";
        cout << "\n file name is: " << temp;
        while (getline(read, line))
        {
            if (line == temp)
            {
                recordFound = 1;
                break;
            }
        }
        if (recordFound == 0)
            return 0;
        else
            return 1;
    }
    else
        return 0;
}

int get_all_std_by_roll()
{
    cout << "\n List of all students by their roll number: ";
    cout << "\n Please press any key to continue..";
    getchar();
    getchar();
    return 0;
}

int delete_all_std()
{
    cout << "\n Delete any students!";
    cout << "\n Press any key to complete.";
    getchar();
    getchar();
    return 0;
}

int delete_std_byroll()
{
    cout << "\n Delete any students by his/her roll number";
    cout << "\n Press any key to complete.";
    getchar();
    getchar();
    return 0;
}

int check_list_of_std_rsg()
{
    cout << "List of all students registered!";
    cout << "\n Press any key to complete.";
    getchar();
    getchar();
    return 0;
}

int check_presence_roll()
{
    cout << "\n Check presence count of all student by roll number.";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int list_present_std_count()
{
    cout << "\n Check presence count of any student by roll number.";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int get_list_std_wt_presence_count()
{
    cout << "\n Check list of students registered by username.";
    ifstream read;
    read.open("db.dat");

    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strcpy(onlyname, name);
            cout << "\n"
                 << onlyname;
        }
        read.close();
    }
    else
    {
        cout << "\n No record found !";
    }
    cout << "\n Press any key to continue..";
    getchar();
    getchar();
    return 0;
}

int registered_std()
{
    cout << "\n List of all registereds students. " << endl;
    cout << "\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int register_std()
{
    cout << "\n ---------- Form To Register Student ----------";
    string name, username, passw, roll, address, fname, mname;
    cout << "\n Enter name: ";
    cin >> name;
    cout << "\n Enter username: ";
    cin >> username;
    cout << "\n Enter password: ";
    cin >> passw;
    cout << "\n Enter roll number: ";
    cin >> roll;
    getchar();
    char add[50];
    cout << "\n Enter your address";
    cin.getline(add, 50);
    cout << "\n Enter Father's name: ";
    cin >> fname;
    cout << "\n Enter Mother's name: ";
    cin >> mname;

    ifstream read;
    read.open("db.dat");
    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            if (line == username + ".dat")
            {
                recordFound = 1;
                break;
            }
        }
        if (recordFound == 1)
        {
            cout << "Username already exist ! Please choose another username.";
            getchar();
            getchar();
            delay();
            read.close();
            return 0;
        }
    }
    read.close();
    ofstream out;
    out.open("db.dat", ios::app);
    cout << username + ".dat"
         << "\n";
    out.close();

    ofstream out1;
    string temp = username + ".dat";
    out1.open(temp.c_str());
    out1 << name << "\n";
    out1 << username << "\n";
    out1 << passw << "\n";
    out1 << roll << "\n";
    out1 << add << "\n";
    out1 << fname << "\n";
    out1 << mname << "\n";
    out1.close();

    cout << "\n Student registered successfully.";
    cout << "\n Press any key to continue.";
    getchar();
    getchar();
    return 0;
}

int mark_attedn(string username)
{
    cout << "\n Mark my attendence for today";
    cout << "Press any key to continue";
    getchar();
    getchar();
    return 0;
}

int count_attend(string username)
{
    cout << "\n Count my attendence for today";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int delay()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 20000; j++)
        {
            for (int k = 0; k < 20000; k++)
            {
            }
        }
    }
    cout << "\n Existing now...";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 20000; j++)
        {
            for (int k = 0; k < 20000; k++)
            {
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    while (1)
    {
        system("cls");
        cout << "\n Attendence Management System\n ";
        cout << "-----------------------------------------------------\n";
        cout << "1. Student Login \n";
        cout << "2. Admin Login \n";
        cout << "0. Exit \n";
        int choice;
        cout << "\n Enter a choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            student_login();
            break;

        case 2:
            admin_login();
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "Are you sure? Want to exit? (Y / N)";
                char ex;
                if (ex == 'y' || ex == 'Y')
                    break;
                else if (ex == 'n' || ex == 'N')
                    break;
                else
                {
                    cout << "\n Invalid choice";
                    getchar();
                }
            }
        default:
            cout << "\n Invalid choice. Enter again";
            getchar();
        }
    }
    return 0;
}
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <cstdio>
using namespace std;

static int p = 0;
class A
{
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} bus[10];
void vline(char ch)
{
    for (int i = 80; i > 0; i--)
    {
        cout << ch;
    }
}
void A ::install()
{
    cout << "Enter the bus number: ";
    cin >> bus[p].busn;
    cout << "\n Enter the driver name: ";
    cin >> bus[p].driver;
    cout << "\n Arrival time: ";
    cin >> bus[p].arrival;
    cout << "\n Departure: ";
    cin >> bus[p].depart;
    cout << "\n From: \t\t\t";
    cin >> bus[p].from;
    cout << "\n To: \t\t\t";
    cin >> bus[p].to;
    bus[p].empty();
    p++;
}

void A::allotment()
{
    int seat;
    char number[5];
top:
    cout << "Bus number: ";
    cin >> number;
    int n;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    while (n <= p)
    {
        cout << "\n Seat Number: ";
        cin >> seat;
        if (seat > 32)
        {
            cout << "\n There are only 32 seats availbale in this bus.";
        }
        else
        {
            if (strcmp(bus[n].seat[(seat / 4)][(seat % 4) - 1], "Empty") == 0)
            {
                cout << "Enter passenger name: ";
                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
                break;
            }
            else
            {
                cout << "The seat number is already reserved. \n";
            }
        }
    }
    if (n > p)
    {
        cout << "Enter correct bus number \n";
        goto top;
    }
}
void A ::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; i < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}
void A::show()
{
    int n;
    char number[5];
    cout << "\nEnter the bus bumber: ";
    cin >> number;
    for (n = 0; n <= p; n++)
    {
        if (strcpy(bus[n].busn, number) == 0)
            break;
    }
    while (n <= p)
    {
        vline('+');
        cout << "Bus no.: \t" << bus[n].busn << "\n Driver: \t" << bus[n].driver << "\t\tArrival Time: \t"
             << bus[n].arrival << "\nDeparture time: \t" << bus[n].depart << "\nFrom: \t\t " << bus[n].from << "\t\tTo: " << bus[n].to << "\n";
        vline('+');
        bus[0].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcpy(bus[n].seat[i][j], "Empty") != 0)
                    cout << "\nThe seat no. " << (a - 1) << "is reserved for " << bus[n].seat[i][j] << ".";
            }
        }
        break;
    }
    if (n > p)
        cout << "Enter correct bus number: ";
}
void A::position(int l)
{
    int s = 0, p = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << "\n\nThere are " << p << "seats empty in Bus no. " << bus[l].busn;
}
void A::avail()
{
    for (int n = 0; n < p; n++)
    {
        vline('+');
        cout << "Bus no.: \t" << bus[n].busn << "\n Driver: \t" << bus[n].driver << "\t\tArrival Time: \t"
             << bus[n].arrival << "\nDeparture time: \t" << bus[n].depart << "\nFrom: \t\t " << bus[n].from << "\t\tTo: " << bus[n].to << "\n";
        vline('+');
        vline('_');
    }
}
int main()
{
    system("cls");
    int w;
    while (1)
    {
        cout << "\n 1. Install";
        cout << "\n 2. Reservation";
        cout << "\n 3. Show";
        cout << "\n 4. Buses Available";
        cout << "\n 5. Exit";
        cin >> w;
        switch (w)
        {
        case 1:
            bus[p].install();
            break;
        case 2:
            bus[p].allotment();
            break;
        case 3:
            bus[p].show();
            break;
        case 4:
            bus[p].avail();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
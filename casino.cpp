#include <iostream>
#include <time.h>
using namespace std;
class Casino
{
private:
    float money;
    string name;
    float betmoney;

public:
    void start_the_game();
    void displaymoney()
    {
        cout << "Your total balance is " << money << endl;
    }
    void rules()
    {
        cout << "Rules of the game.\n";
        cout << "1. There will be a random number.\n";
        cout << "2. You have to guess that number.\n";
        cout << "3. If guessed correctly you will get the doubled of the betting amount.\n";
        cout << "4. If guessed wrong you will loss the betting amount.\n";
    }
};
void Casino::start_the_game()
{
    cout << "Please enter your name.\n";
    cin >> name;
    cout << "Enter the amount\n";
    cin >> money;
    char ch = 'y';
    while (ch == 'y')
    {
        int rnumb = 0, betnum;
        srand(time(0));
        rnumb = (rand() % 10);
        cout << "Enter the betting amount.\n";
        cin >> betmoney;
        if (betmoney <= money)
        {
            cout << "Guess the number(0-10).\n";
            cin >> betnum;
            if (betnum == rnumb)
            {
                cout << "You have guessed right.\n";
                money = money + 2 * betmoney;
                displaymoney();
            }
            else
            {
                cout << "You have guessed wrong\n";
                money = money - betmoney;
                displaymoney();
            }
            cout << "Do you want to play this again.\n";
            cin >> ch;
        }
        else
            cout << "You cannot bet more than your left total balance.\n";
    }
    cout << "Quiting the game...";
}
int main()
{
    cout << "WELCOME TO THE CASINO GAME\n\n";
    char choice;
    Casino s;
    s.rules();
    do
    {
        cout << "Do you want to play the game.(y/n || Y/N)\n";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            s.start_the_game();
            cout << "Starting the game...\n";
        }
    } while (choice != 'n' || choice != 'N');
    cout << "Ok...Have a good day";
    return 0;
}
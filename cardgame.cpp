// The cardsharp shows you three cards, then places them face down on the table and interchanges
// their positions several times. If you can guess correctly where a particular card is, you win.

// The number runs from 2 to 14, where 11, 12, 13, and 14 represent the jack, queen, king, and ace, respectively (this is the order used in poker). The suit runs from 0 to 3, where these four numbers
// represent clubs, diamonds, hearts, and spades
#include <iostream>
using namespace std;

const int clubs = 0;    // suits
const int diamonds = 1; // suits
const int hearts = 2;   // suits
const int spades = 3;   // suits
const int jack = 11;    // number of face cards
const int queen = 12;   // number of face cards
const int king = 13;    // number of face cards
const int ace = 14;     // number of face cards

struct cardgame
{
    int card; // 2 to 10, jack, queen, king, ace
    int suit; // 0 to 3
};
int main()
{
    cardgame temp, choosen, prize;
    int position;
    cardgame card1 = {5, 3};  // this is 5 of spades
    cout<<"Card is 5 of spades\n";
    cardgame card2 = {10, 0}; // this is 10 of clubs
    cout<<"Card is 10 of clubs\n";
    cardgame card3 = {11, 2}; // this is jack of hearts
    cout<<"Card is 11(jack) of hearts\n";
    //taking the copy of the guessing card in another varibale of structure type
    prize = card3;
    // swap card1 with card2
    cout<<"\nI'm Swapping card1 with card2";
    temp = card1;
    card1 = card2;
    card2 = temp;
    // swapping of card2 with card3
    cout<<"\nI'm swapping card2 with card3";
    temp = card2;
    card2 = card3;
    card3 = temp;
    // swapping of card3 with card1
    cout<<"\nI'm swapping card3 with card1\n";
    temp = card1;
    card1 = card3;
    card3 = temp;
    cout<<"====================================================\n";
    cout<<"\nWhere is (1,2 or 3) the jack of hearts?\n";
    cin>>position;
    switch (position)
    {
    case 1:
        choosen = card1;
        break;
    
    case 2:
        choosen = card2;
        break;
    
    case 3:
        choosen = card3;
        break;
    }
    if (choosen.card==prize.card && choosen.suit==prize.suit) //comapre the choosen card with the copy which we have kept previously
    {
        cout<<"\n\n\nYou have won the Game.";
    }
    else cout<<"Sorry! Try again to win the game.";
    return 0;
}
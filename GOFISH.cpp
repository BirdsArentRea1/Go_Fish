#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

// start from slide 10

int main() {
    srand(time(NULL));

    // Game Variables
    string input;
    bool MatchFound = false;
    int PHandSize = 5;
    int CHandSize = 5;
    int NextDeckCard = 10;
    bool HasCard = false;
    int PlayerScore = 0;
    int ComputerScore = 0;
    int turnNumber = 1;
    int computerPick;
    enum TURNS { player, computer };
    int turn = player;
    int quads = 0;
    char match;
    bool isEmpty = false;

    string suits[] = { "Hearts", "Clubs", "Diamonds", "Spades" };
    string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    string deck[52];
    int index = 0;

    // Create deck
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index++] = ranks[j] + " of " + suits[i];
        }
    }

    // Shuffle deck
    random_shuffle(&deck[0], &deck[52]);

   

    // Display shuffled deck
    for (int i = 0; i < 52; i++) {
        cout << deck[i] << endl;
    }

    // create hands
    string PlayerHand[52];
    string ComputerHand[52];
    for (int i = 0; i < 52; i++) {
        PlayerHand[i] = "empty";
        ComputerHand[i] = "empty";
    }

    // Give player 5 cards
    for (int i = 0; i < 5; i++) {
        PlayerHand[i] = deck[i];
        deck[i] = "empty";
    }

    // Give computer 5 cards
    for (int i = 0; i < 5; i++) {
        ComputerHand[i] = deck[i];
        deck[i] = "empty";
    }

    cout << "Welcome to Go Fish!" << endl << endl;
    while (PlayerScore + ComputerScore < 13) {
        cout << endl << endl << endl << "************************************************************" << endl;
        cout << "Turn " turnNumber << endl;
        if (turn == player) cout << "It is your turn" << endl;
        else cout << "computer's turn" << endl;
        cout << "you have " << PHandSize << " cards in your hand, and the computer has " << CHandSize << endl;
        cout << "The scores are You: " << PlayerScore << ", Computer: " << ComputerScore << endl << endl;
        system("pause");
        cout << endl << endl;
    }

    return 0;
}

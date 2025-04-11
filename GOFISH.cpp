#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string suits[] = { "Hearts", "Clubs", "Diamonds", "Spades" };
    string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    string deck[52];
    int index = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index++] = ranks[j] + " of " + suits[i];
        }
    }

    // Shuffle deck
    random_shuffle(&deck[0], &deck[52]);

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

    // Display shuffled deck
    for (int i = 0; i < 52; i++) {
        cout << deck[i] << endl;
    }

    return 0;
}

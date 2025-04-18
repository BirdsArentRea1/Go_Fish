#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

// start from slide 22

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
    string match;
    bool isEmpty = false;

    string suits[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
    string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    string deck[52];
    int index = 0;

    // create deck
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[index++] = ranks[j] + " of " + suits[i];
        }
    }

    // shuffle deck
    random_shuffle(&deck[0], &deck[52]);

    // display shuffled deck 
    /*
    for (int i = 0; i < 52; i++) {
        cout << deck[i] << endl;
    } */

    // create hands
    string PlayerHand[52];
    string ComputerHand[52];
    for (int i = 0; i < 52; i++) {
        PlayerHand[i] = "empty";
        ComputerHand[i] = "empty";
    }

    // give player 5 cards
    for (int i = 0; i < 5; i++) {
        PlayerHand[i] = deck[i];
        deck[i] = "empty";
    }

    // give computer 5 cards
    for (int i = 0; i < 5; i++) {
        ComputerHand[i] = deck[i + 5];
        deck[i + 5] = "empty";
    }

    // Game loop
    cout << "Welcome to Go Fish!" << endl << endl;
    while (PlayerScore + ComputerScore < 13) {
        cout << endl << endl << endl << "************************************************************" << endl;
        cout << "Turn " << turnNumber << endl;
        if (turn == player) cout << "Your turn" << endl;
        else cout << "computer's turn" << endl;
        cout << "you have " << PHandSize << " cards in your hand, and the computer has " << CHandSize << endl;
        cout << "The scores are You: " << PlayerScore << ", Computer: " << ComputerScore << endl << endl;
        system("pause");
        cout << endl << endl;

        switch (turn) {

            // print hands    
        case player:
            sort(PlayerHand, PlayerHand + 52);
            sort(ComputerHand, ComputerHand + 52);
            //cout << "Your hand: " << endl;
            for (int i = 0; i < 52; i++) {
                quads = 0;

                for (int j = i + 1; j < 51; j++) {
                    if (PlayerHand[i].at(0) != 'e') {
                        string rank_i = PlayerHand[i].substr(0, PlayerHand[i].find(" "));
                        string rank_j = PlayerHand[j].substr(0, PlayerHand[j].find(" "));
                        if (rank_i == rank_j) {
                            quads++;
                            if (quads == 3) {
                                match = rank_i;
                                PlayerScore++;
                                cout << "you have a match! +1 point" << endl;
                                for (int m = 0; m < 52; m++) {
                                    if (PlayerHand[m].substr(0, PlayerHand[m].find(" ")) == match)
                                        PlayerHand[m] = "empty";
                                }
                                cout << endl << "Your new hand: " << endl;
                                for (int i = 0; i < 52; i++) {
                                    if (PlayerHand[i].at(0) != 'e')
                                        cout << PlayerHand[i] << endl;
                                }
                            }
                        }
                    }
                }
            }
            cout << endl << "Your current hand: " << endl;
            for (int i = 0; i < 52; i++) {
                if (PlayerHand[i] != "empty")
                    cout << PlayerHand[i] << endl;
            }
            cout << endl << "What card are you looking for? " << endl;
            cin >> input;
            cout << input;
            for (int i = 0; i < 52; i++) {
                if (PlayerHand[i] == input)
                    MatchFound = true;
                //cout << " " << endl;
            }

            if (HasCard == false)
                cout << " You can't ask for that card idiot" << endl;

            for (int i = 0; i < 52; i++) {
                if (MatchFound == false) {
                    cout << "No match found. GO FISH!" << endl;
                    system("pause");
                    cout << "You grabbed a " << deck[NextDeckCard] << endl;
                    PlayerHand[PHandSize] = deck[NextDeckCard];
                    deck[NextDeckCard] = "empty";
                    PHandSize++;
                    NextDeckCard++;
                    turn = computer;
                    turnNumber++;
                }
                else
                    MatchFound = false;
            }

            HasCard = false;
            break;

        case computer:
            cout << endl << endl << "Computer turn!" << endl;

            string pickedCard;

            do {
                computerPick = rand() % 52;
            } while (ComputerHand[computerPick] == "empty");

            pickedCard = ComputerHand[computerPick];


            HasCard = false;

            for (int i = 0; i < 52; i++) {
                if (PlayerHand[i] != "empty") {
                    cout << "The computer takes your " << PlayerHand[i] << "." << endl;
                    ComputerHand[CHandSize++] = PlayerHand[i];
                    PlayerHand[i] = "empty";
                    PHandSize--;
                    HasCard = true;
                    break;
                }
            }

            if (!HasCard) {
                cout << "The computer goes fishing!" << endl;
                if (deck[NextDeckCard] != "empty") {
                    cout << "Computer draws: " << deck[NextDeckCard] << endl;
                    ComputerHand[CHandSize++] = deck[NextDeckCard];
                    deck[NextDeckCard] = "empty";
                    NextDeckCard++;
                }
                else {
                    cout << "Deck is empty. No more cards to draw." << endl;
                }
                turn = player;
                turnNumber++;
            }

            break;
        }
        cout << endl << "************************************************************" << endl;
        cout << "Game Over!" << endl;
        cout << "Final Scores - You: " << PlayerScore << ", Computer: " << ComputerScore << endl;

        if (PlayerScore > ComputerScore) {
            cout << "Congratulations! You won the game of Go Fish!" << endl;
        }
        else if (PlayerScore < ComputerScore) {
            cout << "The computer has defeated you in Go Fish." << endl;
        }
        else {
            cout << "Tie" << endl;
        }

    return 0;
}

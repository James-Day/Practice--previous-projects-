#include <iostream>
using namespace std;

class DiceGame {
    int BIG_WIN = 20;
    int TRIPLE_WIN = 10;
    int SMALL_WIN = 2;
    int WIN_AMOUNT = 100;

public:
    void playGame() {
        int currentMoney = 20;

        bool cont = true;
        string input = "";
        while (currentMoney > 1 && cont) {
            for (int i = 0; i < 25; i++) {
                currentMoney--;
                int diceOne = (rand() % 6) + 1, diceTwo = (rand() % 6) + 1, diceThree = (rand() % 6) + 1;

                if (diceOne == diceTwo && diceTwo == diceThree) {
                    if (diceOne == 1) {
                        currentMoney += BIG_WIN;
                    }
                    else {
                        currentMoney += TRIPLE_WIN;
                    }
                }
                else if (diceOne == diceTwo || diceTwo == diceThree || diceOne == diceThree) {
                    currentMoney += SMALL_WIN;
                }
                cout << currentMoney << endl;

                if (currentMoney >= WIN_AMOUNT) {
                    cout << "Congratulations you won!" << endl;
                    return;
                }
            }
            cout << "Would you like to play 25 more rounds? (y/n): ";

            cin >> input;
            if (input == "y" || input == "Y") {
                cont = true;
            }
            else {
                cont = false;
            }
        }
        cout << "Sorry You've Lost" << endl;
    }

};
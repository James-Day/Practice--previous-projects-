#include <iostream>
using namespace std;

class ChangeMachine {
    int QUARTER_VAL = 25;
    int DIME_VAL = 10;
    int NICKEL_VAL = 5;
    int PENNY_VAL = 1;
public:
    void printChange(int change) {
        if (change > 100) {
            cout << "Change is too high" << endl;
            return;
        }
        int quarters = 0;
        int dimes = 0;
        int nickels = 0;
        int pennies = 0;

        quarters = change / QUARTER_VAL;
        change -= QUARTER_VAL * quarters;

        dimes = change / DIME_VAL;
        change -= DIME_VAL * dimes;

        nickels = change / NICKEL_VAL;
        change -= NICKEL_VAL * nickels;

        pennies = change;

        cout << " Your change is: " << endl;
        cout << quarters << " Quarters" << endl;
        cout << dimes << " Dimes" << endl;
        cout << nickels << " Nickels" << endl;
        cout << pennies << " Pennies" << endl;

    }

    void test() {
        for (int i = 0; i < 100; i++) {
            printChange(i);
            cout << endl;
        }
    }
};
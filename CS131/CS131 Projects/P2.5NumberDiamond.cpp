#include <iostream>
#include <iomanip>
using namespace std;

class numberDiamond {
public:
    void printDiamond(int n) {
        if (n > 9 || n < 2) {
            cout << "Error: please use a number between 2 and 9 next time" << endl;
        }
        for (int i = 1; i <= n; i++) {
            cout << setw(((n+1)-i));
            for (int j = 1; j <= i; j++) {
                cout << j;
            }
            for (int j = i-1; j > 0; j--) {
                cout << j;
            }
            cout << endl;
        }
        for (int i = n; i > 0; i--) {
            cout << setw(-(i-n) + 2);
            for (int j = 1; j < i; j++) {
                cout << j;
            }
            for (int j = i - 2; j > 0; j--) {
                cout << j;
            }
            cout << endl;
        }
    }
};
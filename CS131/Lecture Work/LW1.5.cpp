#include <iostream>
using namespace std;

class LWonePFive {
    public:
    void test() {
        cout << "Please enter 10 positive numbers or a negative to stop" << endl;
        int n = 0;
        int total = 0;
        int numberOfPostiveIntegers = 0;
        for (int i = 1; i < 11; i ++) {
            cout << "Number " << i << ": ";
            cin >> n;
            if (n < 0) {
                break;
            }
            if (n % 2 == 0) {
                total += n;
                numberOfPostiveIntegers++;
            }
        }
        cout << "The total of your " << numberOfPostiveIntegers << " numbers is: " << total;
        cout << "The average for the " << numberOfPostiveIntegers << " numbers is: " << (double)total / numberOfPostiveIntegers;
    }

};
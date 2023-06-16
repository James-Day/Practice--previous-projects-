#include <iostream>
using namespace std;

class LWOne {
public:
    void PrintRandomNums() {
        srand(time(0));
        int ones = 0, twos = 0, threes = 0, fours = 0;
        for (int i = 0; i < 4000; i++)
        {
            int curRand = rand() % 4 + 1;
            switch (curRand) {
            case 1:
                ones++;
                break;
            case 2:
                twos++;
                break;
            case 3:
                threes++;
                break;
            case 4:
                fours++;
                break;
            default:
                cout << "error";
            }
        }
        cout << "Ones: " << ones << endl;
        cout << "Twos: " << twos << endl;
        cout << "Threes: " << threes << endl;
        cout << "Fours: " << fours << endl;
    }
};